library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;

entity FastRequestArbiter_req16 is
	port (
		clk_pcie: in std_logic;
		rst_pcie_n: in std_logic;
		requests: in std_logic_vector(15 downto 0);
		rst_sync: in std_logic;
		req_done: in std_logic;
		selects: out std_logic_vector(15 downto 0);
		ready: out std_logic
	);
end FastRequestArbiter_req16;

architecture MaxDC of FastRequestArbiter_req16 is
	-- Utility functions
	
	function vec_to_bit(v: in std_logic_vector) return std_logic is
	begin
		assert v'length = 1
		report "vec_to_bit: vector must be single bit!"
		severity FAILURE;
		return v(v'left);
	end;
	function bit_to_vec(b: in std_logic) return std_logic_vector is
		variable v: std_logic_vector(0 downto 0);
	begin
		v(0) := b;
		return v;
	end;
	function bool_to_vec(b: in boolean) return std_logic_vector is
		variable v: std_logic_vector(0 downto 0);
	begin
		if b = true then
			v(0) := '1';
		else
			v(0) := '0';
		end if;
		return v;
	end;
	function sanitise_ascendingvec(i : std_logic_vector) return std_logic_vector is
		variable v: std_logic_vector((i'length - 1) downto 0);
	begin
		for j in 0 to (i'length - 1) loop
			v(j) := i(i'high - j);
		end loop;
		return v;
	end;
	function slice(i : std_logic_vector; base : integer; size : integer) return std_logic_vector is
		variable v: std_logic_vector(size - 1 downto 0);
		variable z: std_logic_vector(i'length - 1 downto 0);
	begin
		assert i'length >= (base + size)
		report "vslice: slice out of range."
		severity FAILURE;
		if i'ascending = true then
			z := sanitise_ascendingvec(i);
		else
			z := i;
		end if;
		v(size - 1 downto 0) := z((size + base - 1) downto base);
		return v;
	end;
	function slv_to_slv(v : std_logic_vector) return std_logic_vector is
	begin
		return v;
	end;
	
	-- Component declarations
	
	attribute box_type : string;
	component priority_encoder is
		generic (
			NUM_REQUESTERS : integer;
			NUM_REQUESTERS_WIDTH : integer
		);
		port (
			clk: in std_logic;
			rst: in std_logic;
			eval: in std_logic;
			requests: in std_logic_vector(15 downto 0);
			priority_index: in std_logic_vector(3 downto 0);
			selects: out std_logic_vector(15 downto 0)
		);
	end component;
	component fast_request_arbiter is
		generic (
			NUM_REQUESTERS : integer;
			NUM_REQUESTERS_WIDTH : integer
		);
		port (
			clk: in std_logic;
			rst_sync: in std_logic;
			requests: in std_logic_vector(15 downto 0);
			req_done: in std_logic;
			encoder_result: in std_logic_vector(15 downto 0);
			encoders_eval: out std_logic;
			selects: out std_logic_vector(15 downto 0);
			ready: out std_logic;
			priority_index: out std_logic_vector(3 downto 0)
		);
	end component;
	
	-- Signal declarations
	
	signal pencoder_selects : std_logic_vector(15 downto 0);
	signal fast_request_arbiter_i_encoders_eval : std_logic_vector(0 downto 0);
	signal fast_request_arbiter_i_selects : std_logic_vector(15 downto 0);
	signal fast_request_arbiter_i_ready : std_logic_vector(0 downto 0);
	signal fast_request_arbiter_i_priority_index : std_logic_vector(3 downto 0);
	signal encoders_eval : std_logic_vector(0 downto 0);
	signal priority_index_int : std_logic_vector(3 downto 0);
	
	-- Attribute type declarations
	
	
	-- Attribute declarations
	
begin
	
	-- Assignments
	
	encoders_eval <= fast_request_arbiter_i_encoders_eval;
	priority_index_int <= fast_request_arbiter_i_priority_index;
	selects <= fast_request_arbiter_i_selects;
	ready <= vec_to_bit(fast_request_arbiter_i_ready);
	
	-- Registers
	
	
	-- Entity instances
	
	pencoder : priority_encoder
		generic map (
			NUM_REQUESTERS => 16,
			NUM_REQUESTERS_WIDTH => 4
		)
		port map (
			selects => pencoder_selects, -- 16 bits (out)
			clk => clk_pcie, -- 1 bits (in)
			rst => rst_sync, -- 1 bits (in)
			eval => vec_to_bit(encoders_eval), -- 1 bits (in)
			requests => requests, -- 16 bits (in)
			priority_index => priority_index_int -- 4 bits (in)
		);
	fast_request_arbiter_i : fast_request_arbiter
		generic map (
			NUM_REQUESTERS => 16,
			NUM_REQUESTERS_WIDTH => 4
		)
		port map (
			encoders_eval => fast_request_arbiter_i_encoders_eval(0), -- 1 bits (out)
			selects => fast_request_arbiter_i_selects, -- 16 bits (out)
			ready => fast_request_arbiter_i_ready(0), -- 1 bits (out)
			priority_index => fast_request_arbiter_i_priority_index, -- 4 bits (out)
			clk => clk_pcie, -- 1 bits (in)
			rst_sync => rst_sync, -- 1 bits (in)
			requests => requests, -- 16 bits (in)
			req_done => req_done, -- 1 bits (in)
			encoder_result => pencoder_selects -- 16 bits (in)
		);
end MaxDC;
