#ifndef FILEDEF_H_
#define FILEDEF_H_

#ifdef _WIN32
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
#else
#include<stdint.h>
#endif

//设置成1字节对齐
#pragma pack(1)

//文件头信息
struct FILE_HEAD
{
	char		strCategory[16];				//文件类型
	uint64_t	uiDateTime;						//文件创建与修改日期时间
	uint32_t	uiHeadSize;						//文件头长度
	uint32_t	uiDescSize;						//文件字段描述长度
	uint32_t	uiIndexSize;					//索引长度
	uint32_t	uiRecordSum;					//记录总数
	uint32_t	uiRecordLen;					//每条记录的长度
	uint32_t	uiFieldCount;					//每条记录的字段个数
	uint32_t	uiCodeCount;					//代码个数
};

//文件字段描述信息
struct FIELD_DESC
{
	uint32_t	uiFieldPosition;				//字段位置, from 0
	uint32_t	uiFieldLen;						//记录中每个字段的长度
	char		strFieldType[4];				//字段类型(uint, char)
	uint32_t	uiPrecision;					//小数位(暂未用,置0)
};

//文件索引信息
struct FILE_INDEX
{
	char		strCode[16];					//证券代码
	uint64_t	uiCodeBeginPos;					//代码开始位置
	uint64_t	uiCodeEndPos;					//代码结束位置
};

#define MAX_LEVEL_SIZE   5
#define MAX_LEVEL2_SIZE  10
#define LEVEL2_ORDER_SIZE  50

struct HIS_SNAP_L2
{
	uint64_t	uiDateTime;						//日期时间
	uint32_t	uiPreClosePx;					//昨收价(3)
	uint32_t	uiOpenPx;						//开始价(3)
	uint32_t	uiHighPx;						//最高价(3)
	uint32_t	uiLowPx;						//最低价(3)
	uint32_t	uiLastPx;						//收盘价(3)
	uint32_t	uiNumTrades;					//成交笔数(0)
	char		strInstrumentStatus[8];			//交易状态
	uint64_t	uiTotalVolumeTrade;				//成交总量(3)
	uint64_t	uiTotalValueTrade;				//成交总金额(5)
	uint64_t	uiTotalBidQty;					//委托买入总量(3)
	uint64_t	uiTotalOfferQty;				//委托卖出总量(3)
	uint32_t	uiWeightedAvgBidPx;				//加权平均委买价格（债券共用）(3)
	uint32_t	uiWeightedAvgOfferPx;			//加权平均委卖价格（债券共用）(3)
	uint32_t	uiWithdrawBuyNumber;			//买入撤单笔数(0)
	uint32_t	uiWithdrawSellNumber;			//卖出撤单笔数(0)
	uint64_t	uiWithdrawBuyAmount;			//买入撤单数量(3)
	uint64_t	uiWithdrawBuyMoney;				//买入撤单金额(5)
	uint64_t	uiWithdrawSellAmount;			//卖出撤单数量(3)
	uint64_t	uiWithdrawSellMoney;			//卖出撤单金额(5)
	uint32_t	uiTotalBidNumber;				//买入总笔数(0)
	uint32_t	uiTotalOfferNumber;				//卖出总笔数(0)
	uint32_t	uiBidTradeMaxDuration;			//买入委托成交最大等待时间(0)
	uint32_t	uiOfferTradeMaxDuration;		//卖出委托成交最大等待时间(0)
	uint32_t	uiNumBidOrders;					//买方委托价位数(0)
	uint32_t	uiNumOfferOrders;				//卖方委托价位数(0)
	uint32_t	arrBidPrice[MAX_LEVEL2_SIZE];	//申买价(3)
	uint64_t	arrBidOrderQty[MAX_LEVEL2_SIZE];	//申买量(3)
	uint32_t	arrBidNumOrders[MAX_LEVEL2_SIZE];	//申买十实际总委托笔数(0)
	uint64_t	arrBidOrders[LEVEL2_ORDER_SIZE];	//申买一前50笔订单(3)
	uint32_t	arrOfferPrice[MAX_LEVEL2_SIZE];		//申卖价(3)
	uint64_t	arrOfferOrderQty[MAX_LEVEL2_SIZE];	//申卖量(3)
	uint32_t	arrOfferNumOrders[MAX_LEVEL2_SIZE];	//申卖十实际总委托笔数(0)
	uint64_t	arrOfferOrders[LEVEL2_ORDER_SIZE];	//申卖一前50笔订单(3)
	uint32_t	uiIOPV;							//ETF净值估值（ETF）(3)
	uint32_t	uiETFBuyNumber;					//ETF申购笔数（ETF）(0)
	uint64_t	uiETFBuyAmount;					//ETF申购数量（ETF）(3)
	uint64_t	uiETFBuyMoney;					//ETF申购金额（ETF）(5)
	uint32_t	uiETFSellNumber;				//ETF赎回笔数（ETF）(0)
	uint64_t	uiETFSellAmount;				//ETF赎回数量（ETF）(3)
	uint64_t	uiETFSellMoney;					//ETF赎回金额（ETF）(5)
};

struct HIS_TICK
{
	uint64_t	uiDateTime;						//日期时间
	uint32_t	uiPrice;						//成交价(3)
	uint32_t	uiVolume;						//成交数据量(3)
	uint64_t	uiAmount;						//成交金额(5)
	uint64_t	uiBuyNo;						//买方订单号(0)
	uint64_t	uiSellNo;						//卖方订单号(0)
};

struct HIS_AUCTION
{
	uint64_t	uiDateTime;						//日期时间
	uint32_t	uiPrice;						//成交价(3)
	uint64_t	uiVirtualAuctionQty;			//虚拟匹配量(3)
	uint64_t	uiLeaveQty;						//虚拟未匹配量(3)
	char		strSide[8];						//匹配情况
};

struct HIS_SNAP_SZ2
{
	uint64_t 	dateTime;						//日期时间
	char		streamID[4];					//行情类别
	char		tradingPhaseCode[4];			//交易阶段代码
	int64_t		prevClosePx;					//昨收价(3)
	int64_t		openPx;							//开始价(3)
	int64_t		highPx;							//最高价(3)
	int64_t		lowPx;							//最低价(3)
	int64_t		lastPx;							//最新价(3)
	int64_t		numTrades;						//成交笔数(0)
	int64_t		totalVolumeTrade;				//成交总量(0)
	int64_t		totalValueTrade;				//成交总金额(3)
	int64_t		bidPrice[MAX_LEVEL2_SIZE];		//申买十价(3)
	int64_t		bidSize[MAX_LEVEL2_SIZE];		//申买十量(0)
	int64_t		bidNumOrders[MAX_LEVEL2_SIZE];		//申买价位总委托笔数(0)
	int64_t		bid1OrderQty[LEVEL2_ORDER_SIZE];	//买一价前50笔订单(0)
	int64_t		offerPrice[MAX_LEVEL2_SIZE];	//申卖十价(3)
	int64_t		offerSize[MAX_LEVEL2_SIZE];		//申卖十量(0)
	int64_t		offerNumOrders[MAX_LEVEL2_SIZE];	//申卖价位总委托笔数(0)
	int64_t		offer1OrderQty[LEVEL2_ORDER_SIZE];	//卖一价前50笔订单(0)
	int64_t		change1;						//升跌1(3)
	int64_t		change2;						//升跌2(3)
	int64_t		weightedAvgBidPx;				//委买加权平均价(3)
	int64_t		totalBidQty;					//买入总量(0)
	int64_t		weightedAvgOfferPx;				//委卖加权平均价(3)
	int64_t		totalOfferQty;					//卖出总量(0)
	int64_t		PERatio;						//市盈率(2)
	int64_t		preNAV;							//基金净值(6)
	int64_t		realtimeNAV;					//基金实时参考净值(6)
	int64_t		warrantPremiumRate;				//权证溢价率(3)
	int64_t		upLimitPx;						//涨停价(3)
	int64_t		downLimitPx;					//跌停价(3)
	int64_t		weightedAvgPx;					//实时成交量加权平均利率(5)
	int64_t		weightedAvgPxChange;			//加权平均利率涨跌BP(0)
	int64_t		preCloseWeightedAvgSize;		//昨收盘成交量加权平均利率(0)
	int64_t		longInterest;					//期权持仓量(0)
	uint32_t	stockNum;						//统计量指标样本个数(0)
};

struct HIS_ENTRUST_SZ2
{
	uint64_t	transactTime;					//委托时间(0)
	uint16_t	channelNo;						//频道代码(0)
	int64_t 	applSeqNum;						//消息记录号(0)
	char		streamID[4];					//行情类别
	int64_t		price;							//委托价格(3)
	int64_t		orderQty;						//委托数量(0)
	char		side;							//买卖方向
	char		ordType;						//订单类别
	char		confirmID[8];					//定价行情约定号
	char		contactor[12];					//联系人
	char		contactInfo[32];				//联系方式
	uint64_t	expirationDays;					//期限
	uint64_t	expirationType;					//期限类型
};

struct HIS_TICK_SZ2
{
	uint64_t	transactTime;					//委托时间(0)
	uint16_t	channelNo;						//频道代码(0)
	int64_t 	applSeqNum;						//消息记录号(0)
	char		streamID[4];					//行情类别
	int64_t 	bidApplSeqNum;					//买方委托索引(0)
	int64_t 	offerApplSeqNum;				//卖方委托索引(0)
	int64_t		lastPx;							//委托价格(3)
	int64_t		lastQty;						//委托数量(0)
	char		execType;						//成交类别
};

struct HIS_SNAP_SHO
{
	uint64_t	uiDateTime;						//日期时间
	uint32_t    uiPreSettlePx;					//昨天结算价(4)
	uint64_t	uiOpenPx;						//开始价(4)
	uint64_t	uiHighPx;						//最高价(4)
	uint64_t	uiLowPx;						//最低价(4)
	uint64_t	uiLastPx;						//收盘价(4)
	uint64_t	uiTotalLongPosition;			//当前合约未平仓数量(0)
	uint64_t	uiTotalVolumeTrade;				//成交量(0)
	uint64_t	uiTotalValueTrade;				//成交金额(2)
	uint64_t	arrBidPx[MAX_LEVEL_SIZE];		//申买价(4)
	uint64_t	arrBidSize[MAX_LEVEL_SIZE];		//申买量(0)
	uint64_t	arrOfferPx[MAX_LEVEL_SIZE];		//申卖价(4)
	uint64_t	arrOfferSize[MAX_LEVEL_SIZE];	//申卖量(0)
	char		strPhaseCode[8];				//交易时段
};

struct HIS_SNAP_CFF
{
	uint64_t	dateTime;						//日期时间
	char		settlementGroupID[9];			//结算组代码
	uint32_t	settlementID;					//结算编号(0)
	int64_t		lastPrice;						//最新价(3)
	int64_t		preSettlementPrice;				//昨结算价(3)
	int64_t		preClosePrice;					//昨日收盘价(3)
	int64_t		preOpenInterest;				//昨持仓量(3)
	int64_t		openPrice;						//今日开盘价(3)
	int64_t		highPrice;						//最高成交价(3)
	int64_t		lowPrice;						//最低成交价(3)
	int64_t		volume;							//成交量（0）
	int64_t		turnover;						//成交金额(3)
	int64_t		openInterest;					//持仓量(3)
	int64_t		closePrice;						//今收盘(3)
	int64_t		settlementPrice;				//今结算(3)
	int64_t		upperLimitPrice;				//涨停板价(3)
	int64_t		lowerLimitPrice;				//跌停板价(3)
	int64_t		preDelta;						//昨虚实度(4)
	int64_t		currDelta;						//今虚实度(4)
	int64_t		bidPrice[MAX_LEVEL_SIZE];		//申买价(3)
	int32_t		bidVolume[MAX_LEVEL_SIZE];		//申买量(0)
	int64_t		askPrice[MAX_LEVEL_SIZE];		//申卖价(3)
	int32_t		askVolume[MAX_LEVEL_SIZE];		//申卖量(0)
};

struct HIS_CANDLESTICK
{
	uint64_t	dateTime;			//日期时间(日线：YYYYMMDD, 分钟线：YYYYMMDDHHmmss)
	int32_t		prevClosePx;		//昨收价(3)
	int32_t		openPrice;			//开盘价(3)
	int32_t		highPrice;			//最高价(3)
	int32_t		lowPrice;			//最低价(3)
	int32_t		closePrice;			//收盘价(3)
	int64_t		volume;				//成交量(3)
	int64_t		turnover;			//成交金额(5)
};

#pragma pack()

#endif //FILEDEF_H_