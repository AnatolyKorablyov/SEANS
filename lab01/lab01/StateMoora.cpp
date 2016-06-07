#include "StateMoora.h"



CStateMoora::CStateMoora(const std::string & name, const std::string & output)
	: m_name(name)
	, m_output(output)
{
}

void CStateMoora::SetPath(std::string toName, std::string out)
{
	to.emplace(toName, out);
}