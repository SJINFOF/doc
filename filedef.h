#ifndef FILEDEF_H_
#define FILEDEF_H_

#ifdef _WIN32
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
#else
#include<stdint.h>
#endif

//���ó�1�ֽڶ���
#pragma pack(1)

//�ļ�ͷ��Ϣ
struct FILE_HEAD
{
	char		strCategory[16];				//�ļ�����
	uint64_t	uiDateTime;						//�ļ��������޸�����ʱ��
	uint32_t	uiHeadSize;						//�ļ�ͷ����
	uint32_t	uiDescSize;						//�ļ��ֶ���������
	uint32_t	uiIndexSize;					//��������
	uint32_t	uiRecordSum;					//��¼����
	uint32_t	uiRecordLen;					//ÿ����¼�ĳ���
	uint32_t	uiFieldCount;					//ÿ����¼���ֶθ���
	uint32_t	uiCodeCount;					//�������
};

//�ļ��ֶ�������Ϣ
struct FIELD_DESC
{
	uint32_t	uiFieldPosition;				//�ֶ�λ��, from 0
	uint32_t	uiFieldLen;						//��¼��ÿ���ֶεĳ���
	char		strFieldType[4];				//�ֶ�����(uint, char)
	uint32_t	uiPrecision;					//С��λ(��δ��,��0)
};

//�ļ�������Ϣ
struct FILE_INDEX
{
	char		strCode[16];					//֤ȯ����
	uint64_t	uiCodeBeginPos;					//���뿪ʼλ��
	uint64_t	uiCodeEndPos;					//�������λ��
};

#define MAX_LEVEL_SIZE   5
#define MAX_LEVEL2_SIZE  10
#define LEVEL2_ORDER_SIZE  50

struct HIS_SNAP_L2
{
	uint64_t	uiDateTime;						//����ʱ��
	uint32_t	uiPreClosePx;					//���ռ�(3)
	uint32_t	uiOpenPx;						//��ʼ��(3)
	uint32_t	uiHighPx;						//��߼�(3)
	uint32_t	uiLowPx;						//��ͼ�(3)
	uint32_t	uiLastPx;						//���̼�(3)
	uint32_t	uiNumTrades;					//�ɽ�����(0)
	char		strInstrumentStatus[8];			//����״̬
	uint64_t	uiTotalVolumeTrade;				//�ɽ�����(3)
	uint64_t	uiTotalValueTrade;				//�ɽ��ܽ��(5)
	uint64_t	uiTotalBidQty;					//ί����������(3)
	uint64_t	uiTotalOfferQty;				//ί����������(3)
	uint32_t	uiWeightedAvgBidPx;				//��Ȩƽ��ί��۸�ծȯ���ã�(3)
	uint32_t	uiWeightedAvgOfferPx;			//��Ȩƽ��ί���۸�ծȯ���ã�(3)
	uint32_t	uiWithdrawBuyNumber;			//���볷������(0)
	uint32_t	uiWithdrawSellNumber;			//������������(0)
	uint64_t	uiWithdrawBuyAmount;			//���볷������(3)
	uint64_t	uiWithdrawBuyMoney;				//���볷�����(5)
	uint64_t	uiWithdrawSellAmount;			//������������(3)
	uint64_t	uiWithdrawSellMoney;			//�����������(5)
	uint32_t	uiTotalBidNumber;				//�����ܱ���(0)
	uint32_t	uiTotalOfferNumber;				//�����ܱ���(0)
	uint32_t	uiBidTradeMaxDuration;			//����ί�гɽ����ȴ�ʱ��(0)
	uint32_t	uiOfferTradeMaxDuration;		//����ί�гɽ����ȴ�ʱ��(0)
	uint32_t	uiNumBidOrders;					//��ί�м�λ��(0)
	uint32_t	uiNumOfferOrders;				//����ί�м�λ��(0)
	uint32_t	arrBidPrice[MAX_LEVEL2_SIZE];	//�����(3)
	uint64_t	arrBidOrderQty[MAX_LEVEL2_SIZE];	//������(3)
	uint32_t	arrBidNumOrders[MAX_LEVEL2_SIZE];	//����ʮʵ����ί�б���(0)
	uint64_t	arrBidOrders[LEVEL2_ORDER_SIZE];	//����һǰ50�ʶ���(3)
	uint32_t	arrOfferPrice[MAX_LEVEL2_SIZE];		//������(3)
	uint64_t	arrOfferOrderQty[MAX_LEVEL2_SIZE];	//������(3)
	uint32_t	arrOfferNumOrders[MAX_LEVEL2_SIZE];	//����ʮʵ����ί�б���(0)
	uint64_t	arrOfferOrders[LEVEL2_ORDER_SIZE];	//����һǰ50�ʶ���(3)
	uint32_t	uiIOPV;							//ETF��ֵ��ֵ��ETF��(3)
	uint32_t	uiETFBuyNumber;					//ETF�깺������ETF��(0)
	uint64_t	uiETFBuyAmount;					//ETF�깺������ETF��(3)
	uint64_t	uiETFBuyMoney;					//ETF�깺��ETF��(5)
	uint32_t	uiETFSellNumber;				//ETF��ر�����ETF��(0)
	uint64_t	uiETFSellAmount;				//ETF���������ETF��(3)
	uint64_t	uiETFSellMoney;					//ETF��ؽ�ETF��(5)
};

struct HIS_TICK
{
	uint64_t	uiDateTime;						//����ʱ��
	uint32_t	uiPrice;						//�ɽ���(3)
	uint32_t	uiVolume;						//�ɽ�������(3)
	uint64_t	uiAmount;						//�ɽ����(5)
	uint64_t	uiBuyNo;						//�򷽶�����(0)
	uint64_t	uiSellNo;						//����������(0)
};

struct HIS_AUCTION
{
	uint64_t	uiDateTime;						//����ʱ��
	uint32_t	uiPrice;						//�ɽ���(3)
	uint64_t	uiVirtualAuctionQty;			//����ƥ����(3)
	uint64_t	uiLeaveQty;						//����δƥ����(3)
	char		strSide[8];						//ƥ�����
};

struct HIS_SNAP_SZ2
{
	uint64_t 	dateTime;						//����ʱ��
	char		streamID[4];					//�������
	char		tradingPhaseCode[4];			//���׽׶δ���
	int64_t		prevClosePx;					//���ռ�(3)
	int64_t		openPx;							//��ʼ��(3)
	int64_t		highPx;							//��߼�(3)
	int64_t		lowPx;							//��ͼ�(3)
	int64_t		lastPx;							//���¼�(3)
	int64_t		numTrades;						//�ɽ�����(0)
	int64_t		totalVolumeTrade;				//�ɽ�����(0)
	int64_t		totalValueTrade;				//�ɽ��ܽ��(3)
	int64_t		bidPrice[MAX_LEVEL2_SIZE];		//����ʮ��(3)
	int64_t		bidSize[MAX_LEVEL2_SIZE];		//����ʮ��(0)
	int64_t		bidNumOrders[MAX_LEVEL2_SIZE];		//�����λ��ί�б���(0)
	int64_t		bid1OrderQty[LEVEL2_ORDER_SIZE];	//��һ��ǰ50�ʶ���(0)
	int64_t		offerPrice[MAX_LEVEL2_SIZE];	//����ʮ��(3)
	int64_t		offerSize[MAX_LEVEL2_SIZE];		//����ʮ��(0)
	int64_t		offerNumOrders[MAX_LEVEL2_SIZE];	//������λ��ί�б���(0)
	int64_t		offer1OrderQty[LEVEL2_ORDER_SIZE];	//��һ��ǰ50�ʶ���(0)
	int64_t		change1;						//����1(3)
	int64_t		change2;						//����2(3)
	int64_t		weightedAvgBidPx;				//ί���Ȩƽ����(3)
	int64_t		totalBidQty;					//��������(0)
	int64_t		weightedAvgOfferPx;				//ί����Ȩƽ����(3)
	int64_t		totalOfferQty;					//��������(0)
	int64_t		PERatio;						//��ӯ��(2)
	int64_t		preNAV;							//����ֵ(6)
	int64_t		realtimeNAV;					//����ʵʱ�ο���ֵ(6)
	int64_t		warrantPremiumRate;				//Ȩ֤�����(3)
	int64_t		upLimitPx;						//��ͣ��(3)
	int64_t		downLimitPx;					//��ͣ��(3)
	int64_t		weightedAvgPx;					//ʵʱ�ɽ�����Ȩƽ������(5)
	int64_t		weightedAvgPxChange;			//��Ȩƽ�������ǵ�BP(0)
	int64_t		preCloseWeightedAvgSize;		//�����̳ɽ�����Ȩƽ������(0)
	int64_t		longInterest;					//��Ȩ�ֲ���(0)
	uint32_t	stockNum;						//ͳ����ָ����������(0)
};

struct HIS_ENTRUST_SZ2
{
	uint64_t	transactTime;					//ί��ʱ��(0)
	uint16_t	channelNo;						//Ƶ������(0)
	int64_t 	applSeqNum;						//��Ϣ��¼��(0)
	char		streamID[4];					//�������
	int64_t		price;							//ί�м۸�(3)
	int64_t		orderQty;						//ί������(0)
	char		side;							//��������
	char		ordType;						//�������
	char		confirmID[8];					//��������Լ����
	char		contactor[12];					//��ϵ��
	char		contactInfo[32];				//��ϵ��ʽ
	uint64_t	expirationDays;					//����
	uint64_t	expirationType;					//��������
};

struct HIS_TICK_SZ2
{
	uint64_t	transactTime;					//ί��ʱ��(0)
	uint16_t	channelNo;						//Ƶ������(0)
	int64_t 	applSeqNum;						//��Ϣ��¼��(0)
	char		streamID[4];					//�������
	int64_t 	bidApplSeqNum;					//��ί������(0)
	int64_t 	offerApplSeqNum;				//����ί������(0)
	int64_t		lastPx;							//ί�м۸�(3)
	int64_t		lastQty;						//ί������(0)
	char		execType;						//�ɽ����
};

struct HIS_SNAP_SHO
{
	uint64_t	uiDateTime;						//����ʱ��
	uint32_t    uiPreSettlePx;					//��������(4)
	uint64_t	uiOpenPx;						//��ʼ��(4)
	uint64_t	uiHighPx;						//��߼�(4)
	uint64_t	uiLowPx;						//��ͼ�(4)
	uint64_t	uiLastPx;						//���̼�(4)
	uint64_t	uiTotalLongPosition;			//��ǰ��Լδƽ������(0)
	uint64_t	uiTotalVolumeTrade;				//�ɽ���(0)
	uint64_t	uiTotalValueTrade;				//�ɽ����(2)
	uint64_t	arrBidPx[MAX_LEVEL_SIZE];		//�����(4)
	uint64_t	arrBidSize[MAX_LEVEL_SIZE];		//������(0)
	uint64_t	arrOfferPx[MAX_LEVEL_SIZE];		//������(4)
	uint64_t	arrOfferSize[MAX_LEVEL_SIZE];	//������(0)
	char		strPhaseCode[8];				//����ʱ��
};

struct HIS_SNAP_CFF
{
	uint64_t	dateTime;						//����ʱ��
	char		settlementGroupID[9];			//���������
	uint32_t	settlementID;					//������(0)
	int64_t		lastPrice;						//���¼�(3)
	int64_t		preSettlementPrice;				//������(3)
	int64_t		preClosePrice;					//�������̼�(3)
	int64_t		preOpenInterest;				//��ֲ���(3)
	int64_t		openPrice;						//���տ��̼�(3)
	int64_t		highPrice;						//��߳ɽ���(3)
	int64_t		lowPrice;						//��ͳɽ���(3)
	int64_t		volume;							//�ɽ�����0��
	int64_t		turnover;						//�ɽ����(3)
	int64_t		openInterest;					//�ֲ���(3)
	int64_t		closePrice;						//������(3)
	int64_t		settlementPrice;				//�����(3)
	int64_t		upperLimitPrice;				//��ͣ���(3)
	int64_t		lowerLimitPrice;				//��ͣ���(3)
	int64_t		preDelta;						//����ʵ��(4)
	int64_t		currDelta;						//����ʵ��(4)
	int64_t		bidPrice[MAX_LEVEL_SIZE];		//�����(3)
	int32_t		bidVolume[MAX_LEVEL_SIZE];		//������(0)
	int64_t		askPrice[MAX_LEVEL_SIZE];		//������(3)
	int32_t		askVolume[MAX_LEVEL_SIZE];		//������(0)
};

struct HIS_CANDLESTICK
{
	uint64_t	dateTime;			//����ʱ��(���ߣ�YYYYMMDD, �����ߣ�YYYYMMDDHHmmss)
	int32_t		prevClosePx;		//���ռ�(3)
	int32_t		openPrice;			//���̼�(3)
	int32_t		highPrice;			//��߼�(3)
	int32_t		lowPrice;			//��ͼ�(3)
	int32_t		closePrice;			//���̼�(3)
	int64_t		volume;				//�ɽ���(3)
	int64_t		turnover;			//�ɽ����(5)
};

#pragma pack()

#endif //FILEDEF_H_