CL_CONSUMPTIONREBATE --->>  Client -> Server
CLR_CONSUMPTIONREBATE--->>  Server -> Client

#define MAX_CONSUMPTION_REBATE_ITEM_NUM 300

struct ConsumptionRebate
{
	DWORD dwItemNo0;
	DWORD dwItemNo1;
	DWORD dwItemNo2;
	DWORD dwCousumeCount;
};

struct CL_ConsumptionRebate : public Protocol
{
	void Init() { SetID(CL_CONSUMPTIONREBATE); SetSize( sizeof(CL_CONSUMPTIONREBATE));}
};

struct CLR_ConsumptionRebate: public Protocol, public Response
{
    DWORD m_dwCount;
    ConsumptionRebate m_ConsumptionRebateReward[MAX_CONSUMPTION_REBATE_ITEM_NUM];

    CLR_ConsumptionRebate() { Init(); }
    void Init() { SetID(CLR_CONSUMPTIONREBATE); SetCount(0); SetResponse(1, 0); }
    void SetCount(DWORD dwCount) 
    {
        SetSize((sizeof(CLR_ConsumptionRebate) - sizeof(m_ConsumptionRebateReward)) + (sizeof(ConsumptionRebate) * dwCount));
        m_dwCount = dwCount;
    }
};


CL_CONSUMPTIONREBATE_RECEIVE_SINGLE --->>  Client -> Server
CLR_CONSUMPTIONREBATE_RECEIVE_SINGLE --->>  Server -> Client

struct CL_ConsumptionRebateReceiveSingle : public Protocol
{
	DWORD m_ConsumeCount;

	CL_ConsumptionRevateReceiveSingle() {Init();}
	void Init() {SetID(CL_CONSUMPTIONREBATE_RECEIVE_SINGLE);SetSize(sizeof(*this));}
};

struct CLR_ConsumptionRebateReceiveSingle : public Protocol,Response
{
	BOOL m_IsSucueed;

	CLR_ConsumptionRebateReceiveSingle() {Init();}
	void Init(){SetID(CLR_CONSUMPTIONREBATE_RECEIVE_SINGLE);SetSize(sizeof(*this));}
};

CL_CONSUMPTIONREBATE_RECEIVE_MULTI  --->>  Client -> Server
CLR_CONSUMPTIONREBATE_RECEIVE_MULTI --->>  Server -> Client

struct CL_ConsumptionRebateReceiveMulti : public Protocol
{
	DWORD m_ConsumeCount; //Collect all rewards within the consumption range of 0~m_ConsumeCount

	CL_ConsumptionRebateReceiveMulti() {Init();}
	void Init() {SetID(CL_CONSUMPTIONREBATE_RECEIVE_MULTI);SetSize(sizeof(*this));}
};

struct CLR_ConsumptionRebateReceiveMulti : public Protocol,Response
{
	BOOL m_IsSucueed;

	CLR_ConsumptionRebateReceiveMulti() {Init();}
	void Init(){SetID(CLR_CONSUMPTIONREBATE_RECEIVE_MULTI);SetSize(sizeof(*this));}
};