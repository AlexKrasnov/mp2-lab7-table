#pragma once
#include "Table.h"

class ScanTable : public Table
{
protected:
	TabRecord **rec;
public:
	ScanTable(){};
	ScanTable(int);
	ScanTable(const ScanTable&);
	virtual ~ScanTable();
	virtual TabRecord* Find (KeyType);
	virtual void Ins (KeyType, DataType*);
	virtual void Del (KeyType);
	friend ostream& operator<< (ostream &os, ScanTable &tab)
	{
		setlocale(LC_ALL,"Rus");
		os << "������ �������: " <<endl;
		os<<"+----------------------------------------------------"<<endl;
		for (tab.Reset();!tab.IsTabEnded(); tab.GoNext())
		{
			os << "|\t����: " << tab.rec[tab.GetPos()]->GetKey() 
			   <<" ������: " << tab.rec[tab.GetPos()]->GetData(); os << endl;
		}
		os<<"+----------------------------------------------------"<<endl<<endl;
		return os;
	}
};