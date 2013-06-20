#ifndef MANAGER_BLOCK_H_
#define MANAGER_BLOCK_H_

#include <string>
#include <vector>
#include <tr1/unordered_map>
#include "MappedElements.h"

#include "maxrt_mec_common.h"

namespace maxcompilersim {

class ManagerBlock:
	public MappedElementObserver
{
private:
	const std::string m_name;

	typedef std::tr1::unordered_map<std::string, MappedRegisterPtr> t_mapped_reg_map;
	t_mapped_reg_map m_mapped_reg_map;
	typedef std::tr1::unordered_map<std::string, AbstractMappedMemoryPtr> t_mapped_mem_map;
	t_mapped_mem_map m_mapped_mem_map;

public:
	virtual ~ManagerBlock() {}

	uint32_t getMappedElement(uint32_t address) const;
	void setMappedElement(uint32_t address, uint32_t value, uint mask);

	void mecWriteMappedRegisters(uint32_t address,
									const mapped_registers_data_t *data,
									size_t item_count);

	void mecReadMappedRegisters(uint32_t address,
								mapped_registers_data_t *data,
								size_t item_count) const;

	void mecWriteMappedMemories(uint32_t address,
								const mapped_memories_data_t *data,
								size_t item_count);

	void mecReadMappedMemories(uint32_t address,
								mapped_memories_data_t *data,
								size_t item_count) const;

	void mecDumpMappedMemories() const;

	bool assignAddressToMappedMemory(
		uint32_t address,
		const std::string &name);

	bool assignAddressToMappedRegister(
		uint32_t address,
		const std::string &name);

	virtual void setSimParameter(const std::string &name, const std::string &value) {}
	virtual bool getSimParameter(const std::string &name, std::string &value) { return false; } // or: value="..."; return true;

	const std::string &getName() const;
	virtual void reset() = 0;
	virtual void initialState() {reset();}

protected:
	explicit ManagerBlock(const std::string &name);

	AbstractMappedMemoryPtr registerMappedMemory(
		const std::string &name,
		AbstractMappedMemoryPtr mem);

	MappedMemoryPtr registerMappedMemory(
		const std::string &name,
		uint bit_width,
		uint depth);

	MappedRegisterPtr registerMappedRegister(
		const std::string &name,
		const Data init_value);

	MappedRegisterPtr getMappedReg(const std::string &name);
	AbstractMappedMemoryPtr getMappedMem(const std::string &name);

	virtual void beforeReadMappedRegister() const {}
};

} // namespace maxcompilersim

#endif // MANAGER_BLOCK_H_
