-- Document: Manager Compiler Tutorial (maxcompiler-manager-tutorial.pdf)
-- Chapter: 7
-- Example: 3
-- Name: Mapped Memmory Bus HDL
-- MaxFile name: MappedMemBusHDL
-- Summary:
--     Custom VHDL code for storing data in mapped memories and streaming 
--     it out again.

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mapped_mem_hdl is
	port  (
		clk : in std_logic;
		rst : in std_logic;
		
        output_valid : out std_logic;
        output_stall : in  std_logic;
        output_data  : out std_logic_vector(31 downto 0);

		mapped_mem_data_in : in  std_logic_vector(35 downto 0);
        mapped_mem_addr    : in  std_logic_vector(15 downto 0);
		mapped_mem_wr_en   : in  std_logic;
		mapped_mem_rd_en   : in  std_logic;
		mapped_mem_ack     : out std_logic;
		mapped_mem_data_out: out std_logic_vector(35 downto 0);
		mapped_mem_en_example  : in  std_logic
	);
end mapped_mem_hdl;

architecture arch of mapped_mem_hdl is
    signal output_enable : std_logic := '0';
    signal output_value  : std_logic_vector(31 downto 0) := (others => '0');
    
    signal mapped_mem_wrack_reg : std_logic := '0';
    signal mapped_mem_rdack_reg : std_logic := '0';
    signal mapped_mem_ack_reg : std_logic := '0';
    
    signal mapped_mem_data_out_reg : std_logic_vector(35 downto 0);
    signal mapped_mem_data_out_reg_reg : std_logic_vector(35 downto 0);
begin

    -- Only the the output as valid when the output is not stalled
    output_valid <= output_enable and not output_stall;
    output_data <= output_value;
    
    -- Assign the delayed output signals to the output ports
    mapped_mem_ack <= mapped_mem_ack_reg;
    mapped_mem_data_out <= mapped_mem_data_out_reg_reg;
    -- Delay the output signals so that the response is written a cycle later
    
    -- Process managing reads from the mapped memory bus
    process(clk)
    begin
        if(rising_edge(clk)) then
            mapped_mem_rdack_reg <= '0';
            mapped_mem_data_out_reg <= (others => '0');
            
            if(rst = '1') then
            -- If this Manager block is enabled and a read is requested
            elsif(mapped_mem_en_example = '1' and mapped_mem_rd_en = '1') then
                mapped_mem_data_out_reg <= "00000000000000000000" & mapped_mem_addr;
                mapped_mem_rdack_reg <= '1';
            end if;
        end if;
    end process;
    
    -- Process managing writes to the mapped memory bus
    process(clk)
    begin
        if(rising_edge(clk)) then
            mapped_mem_wrack_reg <= '0';
            
            if(rst = '1') then
                output_enable <= '0';
                output_value  <= (others => '0');
            -- If this Manager block is enabled and a write is requested
            elsif(mapped_mem_en_example = '1' and mapped_mem_wr_en = '1') then
                case mapped_mem_addr is
                when "0000000000000000" =>
                    -- Enable the output
                    output_enable <= mapped_mem_data_in(0);
                when "0000000000000001" =>
                    -- Set the output to the data from the mapped memory bus
                    output_value <= mapped_mem_data_in(31 downto 0);
                when others =>
                    null;
                end case;
                
                mapped_mem_wrack_reg <= '1';
            end if;
        end if;
    end process;
    
    process(clk)
    begin
        if(rising_edge(clk)) then
            if(rst = '1') then
                mapped_mem_ack_reg <= '0';
            else
                -- Or the read and write ack signals together
                mapped_mem_ack_reg <= mapped_mem_wrack_reg or mapped_mem_rdack_reg;
                mapped_mem_data_out_reg_reg <= mapped_mem_data_out_reg;
            end if;
        end if;
    end process;
end arch;
