#pragma once
#include "utils/utils.h"
#include "netvars/dt_recv.h"

class ClientClass
{
public:
    char			header[8];
    const char*		m_pNetworkName;
    RecvTable*		m_pRecvTable;
    ClientClass*	m_pNext;
    int				m_ClassID;
};

class i_base_client_dll {

public:
  ClientClass* get_all_classes() {
	typedef ClientClass*(*fn)(void*);
    return utils::get_virtual_function<fn>(this, 8)(this);
  }
};
