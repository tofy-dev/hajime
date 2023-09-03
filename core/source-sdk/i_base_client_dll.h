#pragma once
#include "utils/utils.h"
#include "netvars/dt_recv.h"
#include "i_entity.h"
#include "structs/structs.h"

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

class i_client_mode_shared {
public:
  virtual bool create_move(float flInputSampleTime, c_user_cmd* cmd) {
    typedef bool(*fn)(void*, float, c_user_cmd*);
    return utils::get_virtual_function<fn>(this, 22)(this, flInputSampleTime, cmd);
  }
};
