#pragma once
#include "NotDeterStatesment.h"
#include "MelleeStatesment.h"

class CTransferMelleeToNoDeterm
{
public:
	CTransferMelleeToNoDeterm(CMelleeStatesment &notDeterData);
	CNotDeterStatesment m_deterData;
};