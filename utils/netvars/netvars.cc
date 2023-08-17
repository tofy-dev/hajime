#include "netvars.h"
#include "dt_recv.h"
#include "interfaces/interfaces.h"

#include <cstdint>
#include <map>
#include <fstream>
#include <string.h>

#define RECV_SIZE 8192 
RecvTable *recvTables[RECV_SIZE];

void netvars::init() {
	ClientClass* clientClass = interfaces::client->get_all_classes();

	if(!clientClass)
		return;

	int x = 0;

	while (clientClass)
	{
		if(!clientClass)
			continue;

		RecvTable *recvTable = clientClass->m_pRecvTable;
		recvTables[x] = recvTable;

		clientClass = clientClass->m_pNext;
		x++;
	}
}

int netvars::get_netvar(const char* dt, const char* m) {
	for (int i = 0; i < sizeof(recvTables)/sizeof(*recvTables); i++)
	{
		if(recvTables[i] != NULL)
		{
			if(!strcmp(recvTables[i]->m_pNetTableName, dt))
			{
				for(int x = 0; x < recvTables[i]->m_nProps; x++)
				{
					if(!strcmp(recvTables[i]->m_pProps[x].m_pVarName, m))
					{
                        offsets_.insert({m, recvTables[i]->m_pProps[x].get_offset()});
						return recvTables[i]->m_pProps[x].get_offset();
					}
				}
			}
		}
	}
}

void netvars::dump_netvars() {
  std::ofstream ofs;
  ofs.open("/tmp/netvardump.txt", std::ofstream::out);

	for (int i = 0; i < sizeof(recvTables)/sizeof(*recvTables); i++)
	{
		if(recvTables[i] != nullptr)
		{
          ofs << recvTables[i]->m_pNetTableName << std::endl;
          ofs << "-----------------------------------------" << std::endl;
          for(int x = 0; x < recvTables[i]->m_nProps; x++)
          {
		      ofs << recvTables[i]->m_pProps[x].m_pVarName << std::endl;
          }
          ofs << std::endl;
		}
	}
    ofs.flush();
}

void netvars::print_offsets() {
  for (const auto& kvp : offsets_) {
    // *Debug::ofs << "Key: " << kvp.first << ", Value: " << kvp.second << std::endl;
  }
}

// Obtaining offsets post-dump
uint32_t netvars::get_offset(char* name) {
  return offsets_[name];
}

namespace netvars {
  std::map<const char*, int> offsets_{};
}
