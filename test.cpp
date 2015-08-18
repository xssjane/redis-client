/**
 *
 * @file	main.cpp
 * @brief CRedisClient 测试代码。
 *
 * @author: 		yuhaiyang
 * @date: 		2015年6月14日
 *
 * 修订说明:初始版本
 */
#include <iostream>
#include "Command.h"
#include "CRedisClient.h"
#include <stdio.h>
#include <sstream>
#include "RdException.hpp"
#include "CResult.h"

using namespace std;




void TestKey( void )
{
    try
    {
        CRedisClient redis;
        redis.connect( "127.0.0.1", 6379 );
        for ( int i = 0; i < 5 ; i++ )
        {
            CRedisClient::VecString value;
            //--------------------------keys------------------------------
            std::cout << "keysNum:" << redis.keys("test*", value ) << std::endl;
            CRedisClient::VecString::iterator it = value.begin();

            std::cout << "------------------------start value---------------------------" << std::endl;
            for ( ; it != value.end(); it++ )
            {
                DEBUGOUT( "value", *it );
            }
            std::cout << "----------------------end value----------------------------" << std::endl;

            CRedisClient::VecString keys;
            keys.push_back( "testStringList" );
            keys.push_back( "testString" );
            uint64_t num = redis.del( keys );

            std::cout << "del data:" << num << std::endl;

            sleep( 1 );
        }
    }catch( RdException& e )
    {
        std::cout << "Redis exception:" << e.what() << std::endl;
    }catch( Poco::Exception& e )
    {
        std::cout << "Poco_exception:" << e.what() << std::endl;
    }
}

void TestList( void )
{
    try
    {
        CRedisClient::VecString value;
        string ret;
        value.push_back( "yu" );

        CRedisClient redis;
        redis.connect( "127.0.0.1", 6379 );
        for ( int i = 0; i < 5 ; i++ )
        {
            std::cout << "======================testList=========================" << std::endl;
            int64_t listNum1 = redis.lpush( "name", value );
            std::cout << "listNum1:" << listNum1 << std::endl;

            int32_t listNum2 = redis.lpop( "name", ret );
            std::cout << "listNume2: " << listNum2 << std::endl;
            std::cout << "listRet: " << ret << std::endl;

            sleep( 1 );
        }
    }catch( RdException& e )
    {
        std::cout << "Redis exception:" << e.what() << std::endl;
    }catch( Poco::Exception& e )
    {
        std::cout << "Poco_exception:" << e.what() << std::endl;
    }
}

void TestString( void )
{
    try
    {
        CRedisClient redis;
        redis.connect( "127.0.0.1", 6379 );
        std::cout << "======testString======" << std::endl;
        std::cout << "------testAPPEND------" << std::endl;
        uint16_t iRet = redis.append("myphone", "nokia");
        std::cout << "iRet: " << iRet << std::endl;
        std::string value;
        bool bRet = redis.get("myphone", value);
        std::cout << "bRet: " << bRet << std::endl;
        std::cout << "value:" << value << std::endl;

        //	std::cout << "------testBITCOUNT------" << std::endl;
        //	uint64_t iRet = redis.bitcount("bits", 0, -1);
        //	std::cout << "iRet: " << iRet << std::endl;
        //	iRet = redis.setbit("bits", 0, "1");
        //	std::cout << "iRet: " << iRet << std::endl;
        //	iRet = redis.bitcount("bits");
        //	std::cout << "iRet: " << iRet << std::endl;

        //        std::cout << "------testBITOP------" << std::endl;
        //        //bits-1 = 1001
        //        redis.setbit("bits-1", 0, "1");
        //        redis.setbit("bits-1", 3, "1");
        //        //bits-2 = 1011
        //        redis.setbit("bits-2", 0, "1");
        //        redis.setbit("bits-2", 1, "1");
        //        redis.setbit("bits-2", 3, "1");
        //
        //        CRedisClient::VecString keys;
        //        keys.push_back("bits-1");
        //        keys.push_back("bits-2");
        //        uint64_t iRet = redis.bitop("AND", "and-result", keys);
        //        std::cout << "iRet: " << iRet << std::endl;
        //
        //        iRet = redis.getbit("and-result", 0);
        //        std::cout << "iRet: " << iRet << std::endl;
        //	iRet = redis.getbit("and-result", 1);
        //	std::cout << "iRet: " << iRet << std::endl;
        //	iRet = redis.getbit("and-result", 2);
        //	std::cout << "iRet: " << iRet << std::endl;
        //	iRet = redis.getbit("and-result", 3);
        //	std::cout << "iRet: " << iRet << std::endl;

        //	std::cout << "------testDECR------" << std::endl;
        //	redis._set("failure_times", "10");
        //	int64_t iRet = redis.decr("failure_times");
        //	std::cout << "iRet: " << iRet << std::endl;

        //	std::cout << "------testDECRBY------" << std::endl;
        //	redis._set("count", "100");
        //	int64_t iRet = redis.decrby("count", 20);
        //	std::cout << "iRet: " << iRet << std::endl;

        //	std::cout << "------testGET------" << std::endl;
        //	redis._set("db", "redis");
        //	std::string value;
        //	int64_t iRet = redis.get("db", value);
        //	std::cout << "iRet: " << iRet << std::endl;
        //	std::cout << "value:" << value << std::endl;

        //	std::cout << "------testGETBIT------" << std::endl;
        //	redis.setbit("bit", 10086, "1");
        //	int iRet = redis.getbit("bit", 10086);
        //	std::cout << "iRet: " << iRet << std::endl;

        //	std::cout << "------testGETRANGE------" << std::endl;
        //	redis._set("greeting", "hello, my friend");
        //	std::string value;
        //	redis.getrange("greeting", 0, 4, value);
        //	std::cout << "value:" << value << std::endl;

        //	std::cout << "------testGETSET------" << std::endl;
        //	std::string oldvalue;
        //	bool bRet = redis.getset("db", "mongodb", oldvalue);
        //	std::cout << "bRet: " << bRet << std::endl;
        //	redis.get("db", oldvalue);
        //	std::cout << "oldvalue:" << oldvalue << std::endl;
        //	bRet = redis.getset("db", "redis", oldvalue);
        //	std::cout << "bRet: " << bRet << std::endl;
        //	std::cout << "oldvalue:" << oldvalue << std::endl;
        //	redis.get("db", oldvalue);
        //	std::cout << "oldvalue:" << oldvalue << std::endl;

        //	std::cout << "------testINCR------" << std::endl;
        //	redis._set("page_view", "20");
        //	int64_t iRet = redis.incr("page_view");
        //	std::cout << "iRet: " << iRet << std::endl;
        //	std::string value;
        //	redis.get("page_view", value);
        //	std::cout << "value:" << value << std::endl;

        //	std::cout << "------testINCRBY------" << std::endl;
        //	redis._set("rank", "50");
        //	int64_t iRet = redis.incrby("rank", 20);
        //	std::cout << "iRet: " << iRet << std::endl;
        //	std::string value;
        //	redis.get("rank", value);
        //	std::cout << "value:" << value << std::endl;

        //	std::cout << "------testINCRBYFLOAT------" << std::endl;
        //	redis._set("mykey", "10.50");
        //	float fRet = redis.incrbyfloat("mykey", 0.1);
        //	std::cout << "fRet: " << fRet << std::endl;
        //	std::string value;
        //	redis.get("mykey", value);
        //	std::cout << "value:" << value << std::endl;


        //	std::cout << "------testMGET------" << std::endl;
        //	redis._set("redis", "redis.com");
        //	redis._set("mongodb", "mongodb.org");
        //	CRedisClient::VecString keys;
        //	keys.push_back("redis");
        //	keys.push_back("mongodb");
        //	CResult result;
        //	redis.mget(keys, result);
        //
        //	CResult::ListCResult::const_iterator it = result.getArry().begin();
        //	CResult::ListCResult::const_iterator end = result.getArry().end();
        //	for ( ; it != end; ++it )
        //	{
        //		std::cout << "value: " << static_cast<string>(*it) << std::endl;
        //	}

        //	std::cout << "------testMSET------" << std::endl;
        //	CRedisClient::MapString value;
        //	value["date"] = "2012.3.30";
        //	value["time"] = "11:00 a.m.";
        //	value["weather"] = "sunny";
        //	redis.mset(value);
        //
        //	CResult result;
        //	CRedisClient::VecString keys;
        //	keys.push_back("date");
        //	keys.push_back("time");
        //	keys.push_back("weather");
        //	redis.mget(keys, result);
        //	CResult::ListCResult::const_iterator it = result.getArry().begin();
        //	CResult::ListCResult::const_iterator end = result.getArry().end();
        //	for ( ; it != end; ++it )
        //	{
        //		std::cout << "value: " << static_cast<string>(*it) << std::endl;
        //	}

        //	std::cout << "------testMSETNX------" << std::endl;
        //	CRedisClient::MapString value;
        //	value["rmdbs"] = "MySQL";
        //	value["nosql"] = "MongoDB";
        //	value["key-value-store"] = "redis";
        //	int iRet = redis.msetnx(value);
        //	std::cout << "iRet: " << iRet << std::endl;
        //
        //	CResult result;
        //	CRedisClient::VecString keys;
        //	keys.push_back("rmdbs");
        //	keys.push_back("nosql");
        //	keys.push_back("key-value-store");
        //	redis.mget(keys, result);
        //	CResult::ListCResult::const_iterator it = result.getArry().begin();
        //	CResult::ListCResult::const_iterator end = result.getArry().end();
        //	for ( ; it != end; ++it )
        //	{
        //		std::cout << "value: " << static_cast<string>(*it) << std::endl;
        //	}

        //	std::cout << "------testPSETEX------" << std::endl;
        //	bool bRet = redis.setPX("mykey", "Hello", 1000);
        //	std::cout << "bRet: " << bRet << std::endl;
        //	std::string value;
        //	redis.get("mykey", value);
        //	std::cout << "value:" << value << std::endl;

        //	std::cout << "------testPSET------" << std::endl;
        //	CResult result;
        //	redis._set("key-with-expire-and-NX", "hello", result, "EX", 10086, "NX");
        //	std::string status = result.getStatus();
        //	std::cout << "status:" << status << std::endl;
        //	std::string value;
        //	redis.get("key-with-expire-and-NX", value);
        //	std::cout << "value:" << value << std::endl;

        //	std::cout << "------testSETBIT------" << std::endl;
        //	int iRet = redis.setbit("bit", 10086, "1");
        //	std::cout << "iRet: " << iRet << std::endl;
        //	iRet = redis.getbit("bit", 10086);
        //	std::cout << "iRet: " << iRet << std::endl;

        //	std::cout << "------testSETEX------" << std::endl;
        //	bool bRet = redis.setEX("cache_user_id", "10086", 60);
        //	std::cout << "bRet: " << bRet << std::endl;
        //	std::string value;
        //	redis.get("cache_user_id", value);
        //	std::cout << "value:" << value << std::endl;

        //	std::cout << "------testSETNX------" << std::endl;
        //	bool bRet = redis.setNX("job", "programmer");
        //	std::cout << "bRet: " << bRet << std::endl;
        //	std::string value;
        //	redis.get("job", value);
        //	std::cout << "value:" << value << std::endl;
        //
        //	bRet = redis.setXX("job", "code-farmer");
        //	std::cout << "bRet: " << bRet << std::endl;
        //	redis.get("job", value);
        //	std::cout << "value:" << value << std::endl;

        //	std::cout << "------testSETRANGE------" << std::endl;
        //	redis._set("greeting", "hello world");
        //	uint64_t iRet = redis.setrange("greeting", 6, "Redis");
        //	std::cout << "iRet: " << iRet << std::endl;
        //	std::string value;
        //	redis.get("greeting", value);
        //	std::cout << "value:" << value << std::endl;

        //	std::cout << "------testSTRLEN------" << std::endl;
        //	redis._set("mykey", "Hello world");
        //	uint64_t iRet = redis.strlen("mykey");
        //	std::cout << "iRet: " << iRet << std::endl;
    }catch( RdException& e )
    {
        std::cout << "Redis exception:" << e.what() << std::endl;
    }catch( Poco::Exception& e )
    {
        std::cout << "Poco_exception:" << e.what() << std::endl;
    }
}




///////////////////////////////////////// test CResult////////////////////////////////////////
//int main()
//{
//    CResult result("123");
//    result.setType( REDIS_REPLY_STRING );
//
//    result += "345";
//    CResult result2  ;
//    result2 = result;
//
//
//   // result.clear();
//
//    std::cout << result<< std::endl;
//    std::cout << result2<< std::endl;
//}


/*
int main()
{
    CRedisClient redis;
    redis.connect( "127.0.0.1", 6379 );
    CRedisClient::VecString keys;
    keys.push_back( "user_name_4");

    redis.watch(  keys );

    return 0;
}
*/



void testReadN( void )
{
    try
    {

        CRedisClient redis;
        redis.connect("127.0.0.1", 6379);
        string mykey = "special";
        string val ="{\"a\":\"ok\"\r\n}";
        redis.set(mykey, val);

        if ( redis.get(mykey, val) )
        {
            std::cout << "my val:" << val << std::endl;
        }
        else
        {
            std::cout << "get failed:" << val << std::endl;
        }


        //------------------------test hlen-----------------------------------------------
        string myhx="myhx";
        uint64_t fieldNum = redis.hlen(myhx);
        std::cout << "fieldNum: " << fieldNum << std::endl;
        //------------------------test hmget---------------------------------------------
        CResult result;
        CRedisClient::VecString hmgeFields;
        hmgeFields.push_back("a");
        hmgeFields.push_back("f");
        hmgeFields.push_back("c");
        for(int i=0;i<1;i++){
            redis.hmget(myhx, hmgeFields, result);
            std::cout << "hmget:" << std::endl;
            std::cout << result << std::endl;
        }
    } catch( RdException& e )
    {
        std::cout << "Redis exception:" << e.what() << std::endl;
    } catch( Poco::Exception& e )
    {
        std::cout << "Poco_exception:" << e.what() << std::endl;
    }
}



void testpsubscribecallback(CResult& result, void* pData)
{
	ReplyType type = result.getType();

	if ( REDIS_REPLY_ERROR == type )
	{
		throw ReplyErr( result.getErrorString() );
	}
	if ( REDIS_REPLY_ARRAY != type )
	{
		throw ProtocolErr( "testpsubscribecallback: data recved is not arry" );
	}

	CResult::ListCResult::const_iterator it = result.getArry().begin();
	CResult::ListCResult::const_iterator end = result.getArry().end();

	for ( ; it != end; ++it )
	{
		std::cout << "value: " <<  static_cast<string>(*it) << std::endl;
	}
}

void TestPSub( void )
{
    try
    {
        CRedisClient redis;
        redis.connect( "127.0.0.1", 6379 );


        std::cout << "======testPSub======" << std::endl;

        std::cout << "------testPUBLISH------" << std::endl;
        uint64_t iRet = redis.publish("msg", "good morning");
        std::cout << "iRet: " << iRet << std::endl;


        std::cout << "------testPUBSUB CHANNELS------" << std::endl;
        CRedisClient::VecString pattern, value;
        redis.psubchannels(pattern, value);
        CRedisClient::VecString::const_iterator it = value.begin();
        CRedisClient::VecString::const_iterator end = value.end();
        for ( ; it != end; ++it )
        {
            std::cout << "value: " << static_cast<string>(*it) << std::endl;
        }

//	std::cout << "------testPSUBSCRIBE------" << std::endl;
//	CRedisClient::VecString pattern;
//	pattern.push_back("news.*");
//	pattern.push_back("tweet.*");
//	redis.psubscribe(pattern, testpsubscribecallback, NULL);




//    std::cout << "------testPUBLISH------" << std::endl;
//    uint64_t iRet = redis.publish("msg", "good morning");
//    std::cout << "iRet: " << iRet << std::endl;


//    std::cout << "------testPUBSUB CHANNELS------" << std::endl;
//    CRedisClient::VecString pattern, value;
//    redis.psubchannels(pattern, value);
//    CRedisClient::VecString::const_iterator it = value.begin();
//    CRedisClient::VecString::const_iterator end = value.end();
//    for ( ; it != end; ++it )
//    {
//        std::cout << "value: " << static_cast<string>(*it) << std::endl;
//    }


        //	std::cout << "------testPUBSUB NUMSUB------" << std::endl;
        //	CRedisClient::VecString channel;
        //	channel.push_back("news.it");
        //	channel.push_back("news.internet");
        //	channel.push_back("news.sport");
        //	channel.push_back("news.music");
        //	CRedisClient::MapString value;
        //	redis.psubnumsub(channel, value);
        //	CRedisClient::MapString::const_iterator it = value.begin();
        //	CRedisClient::MapString::const_iterator end = value.end();
        //	for ( ; it != end; ++it )
        //	{
        //		std::cout << "value first: " << static_cast<string>(it->first) << std::endl;
        //		std::cout << "value second: " << static_cast<string>(it->second) << std::endl;
        //	}




        //	std::cout << "------testPUBSUB NUMPAT------" << std::endl;
        //	uint64_t iRet = redis.psubnumpat();
        //	std::cout << "iRet: " << iRet << std::endl;



        //	std::cout << "------testPUNSUBSCRIBE------" << std::endl;
        //	CRedisClient::VecString pattern;
        //	CResult result;
        //	redis.punsubscribe(pattern, result);



        //	std::cout << "------testUNSUBSCRIBE------" << std::endl;
        //	CRedisClient::VecString channel;
        //	CResult result;
        //	redis.unsubscribe(channel, result);


    }catch( RdException& e )
    {
        std::cout << "Redis exception:" << e.what() << std::endl;
    }catch( Poco::Exception& e )
    {
        std::cout << "Poco_exception:" << e.what() << std::endl;
    }
}

typedef CRedisClient::VecString VEC;
typedef CRedisClient::MapString MAP;

void print(const string &cmd,uint64_t num)
{
    cout<<cmd<<":"<<num<<endl;
    cout<<endl;
}
void print(const string &cmd,string str)
{
    cout<<cmd<<":"<<str<<endl;
    cout<<endl;
}
void print(const string& cmd,VEC& vec)
{
    cout<<cmd<<":"<<endl;
    VEC::const_iterator it = vec.begin();
    VEC::const_iterator end = vec.end();
    for ( ; it != end; ++it )
    {
        cout<<*it<<endl;
    }
    cout<<endl;
}
void print(const string &cmd,MAP& map)
{
    cout<<cmd<<":"<<endl;
    MAP::const_iterator it = map.begin();
    MAP::const_iterator end = map.end();
    for ( ; it != end; ++it )
    {
        cout << it->first << ":     " << it->second << endl;
    }
    cout<<endl;
}


void TestSortedSet( void )
{
    try
    {
        CRedisClient redis;
        redis.connect( "127.0.0.1", 6379 );
        redis.flushall();
        MAP map;
        VEC vec;
        string key,key1,key2;
        key="sortedSet0";
        key1="sortedSet1";
        key1="sortedSet2";
        //--------------------------------------------------------------------------------------------------------------------
        cout << "------test zadd------" << endl;
        string score,member;
        std::stringstream ss;
        int i;
        for ( i = 1; i <= 100; i++ )
        {

            member="member_";
            ss.str("");
            ss << i;
            score= ss.str();
            member += ss.str();
            map.insert( CRedisClient::MapString::value_type(score,member) );
        }
        print("redis.zadd(key,map)",redis.zadd(key,map));
        //------------------------------------------------------------------------------------------------------------------
        cout << "------test zcard------" << endl;
        print("redis.zcard(key)",redis.zcard(key));
        //-------------------------------------------------------------------------------------------------------------------
        cout << "------test zcount------" << endl;
        print( "zcount",redis.zcount(key,"35","98") );
        //-------------------------------------------------------------------------------------------------------------------
        cout << "------test zincrby------" << endl;
        string tmp;
        //tmp=redis.zincrby("hash",1,"a");
        tmp=redis.zincrby(key,1,"member_45");
        print("redis.zincrby(key,1,member_45)",tmp);
        //--------------------------------------------------------------------------------------------------------------------
        cout << "------test zrange------" << endl;
        redis.zrange(key,1,10,vec);
        print("redis.zrange(key,1,10,vec)",vec);
        //--------------------------------------------------------------------------------------------------------------------
        map.clear();
        redis.zrange(key,1,10,map);
        print("redis.zrange(key,1,10,map)",map);
       //---------------------------------------------------------------------------------------------------------------------
       cout << "------test zrangebyscore------" << endl;
       vec.clear();
       redis.zrangebyscore(key,"20","50",vec,0,10);
       print("redis.zrangebyscore(key,20,50,vec,0,10)",vec);

       map.clear();
       redis.zrangebyscore(key,"20","50",map,1,10);
       print("redis.zrangebyscore(key,20,50,map,1,10)",map);
        //---------------------------------------------------------------------------------------------------------------------
        cout << "------test zrank------" << endl;
        int64_t num;
        print("redis.zrank(key,member_600,num)",redis.zrank(key,"member_600",num));
       //---------------------------------------------------------------------------------------------------------------------
       cout << "------test zrem------" << endl;
       vec.clear();
       vec.push_back( "member_99");
       vec.push_back( "member_100" );
       print("redis.zrem(key,vec)",redis.zrem( "sortedSet0",vec));
        //--------------------------------------------------------------------------------------------------------------------
        cout << "------test zremrangebyrank------" << endl;
        print("redis.zremrangebyrank(key,1,5)",redis.zremrangebyrank(key,1,5));
        //--------------------------------------------------------------------------------------------------------------------
        cout << "------test zremrangebyscore------" << endl;
        print("redis.zremrangebyscore(key,(40,90)",redis.zremrangebyscore( "sortedSet0","(40","90"));
        //--------------------------------------------------------------------------------------------------------------------
        cout << "------test zrevrange------" << endl;
        map.clear();
        vec.clear();
        for ( i = 1; i <= 100; i++ )
        {

            member="member_";
            ss.str("");
            ss << i;
            score= ss.str();
            member += ss.str();
            map.insert( CRedisClient::MapString::value_type(score,member) );
        }
        redis.flushall();
        redis.zadd(key,map);
        redis.zrevrange(key,40,-1,vec);
        print("redis.zrevrange(key,40,-1,vec)",vec);
        //---------------------------------------------------------------------------------------------------------------------
        cout << "------test zrevrangebyscore------" << endl;
        vec.clear();
        redis.zrevrangebyscore(key,"23","(10",vec, 2, 4 );
        print("redis.zrevrange(key,23,(10,vec, 2, 4)",vec);
        map.clear();
        redis.zrevrangebyscore(key,"(23","10",map , 2,4 );
        print("redis.zrevrange(key,(23,10,map, 2, 4 )",map);
        //---------------------------------------------------------------------------------------------------------------------
        cout << "------test zrevrank------" << endl;
        print("redis.zrevrank(key,member_87)",redis.zrevrank(key,"member_87"));
        //---------------------------------------------------------------------------------------------------------------------
        cout << "------test zscore------" << endl;
        print("zscore(key,member_87)",redis.zscore("asd","member_87"));
        //---------------------------------------------------------------------------------------------------------------------
        cout << "------test zunionstore------" << endl;
        map.clear();
        for ( i = 40; i <= 125; i++ )
        {
            member="member_";
            ss.str("");
            ss << i;
            score= ss.str();
            member += ss.str();
            map.insert( CRedisClient::MapString::value_type(score,member) );
        }
        redis.zadd(key1,map);
        vec.clear();
        vec.push_back(key);
        vec.push_back(key1);
        print("redis.zunionstore(key2,2,vec,1)",redis.zunionstore(key2,2,vec,1));
        //---------------------------------------------------------------------------------------------------------------------
        cout << "------test zinterstore------" << endl;
        map.clear();
        vec.clear();
        vec.push_back(key);
        vec.push_back(key1);
        print("redis.zinterstore(key2,2,vec,2)",redis.zinterstore(key2,2,vec,2));
        cout << "------test zscan------" << endl;
        redis.zscan( key, 0, map);
        print("redis.zscan( key, 0, map ,)",map);
        while ( redis.zscan(key, -1, map ) );

        print("redis.zscan( key, -1, map )",map);
        //----------------------------------------------------------------------------------------------------------------------
        vec.clear();
        cout << "------test zrangebylex------" << endl;
        redis.zrangebylex(key,"(10","(60",vec);
        print("redis.zrangebylex(key,(10,(60,vec)",vec);
        //----------------------------------------------------------------------------------------------------------------------
        cout << "------test zlexcount------" << endl;
        print("redis.zlexcount(key,10,(60)",redis.zlexcount(key,"(10","(60"));
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test zremrangebylex------" << endl;
        print("redis.zremrangebylex(key,10,(60)",redis.zremrangebylex(key,"(10","(60"));
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test finish------" << endl;
        sleep( 1 );
    }catch( RdException& e )
    {
        std::cout << "Redis exception:" << e.what() << std::endl;
    }catch( Poco::Exception& e )
    {
        std::cout << "Poco_exception:" << e.what() << std::endl;
    }
}
void TestServer( void )
{
    try
    {
        CRedisClient redis;
        redis.connect( "127.0.0.1", 6379 );
        VEC  vec;
        string str;
        CResult res;
        //-----------------------------------------------------------------------------------------------------------------------
       // cout << "------test bgrewriteaof------" << endl;
       // print("redis.bgrewriteaof()",redis.bgrewriteaof());
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test bgsave------" << endl;
        print("redis.bgsave()",redis.bgsave());
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test clientSetname------" << endl;
        print("redis.clientSetname(qwert)",redis.clientSetname("qwert"));
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test clientGetname------" << endl;
        print("redis.clientGetname()",redis.clientGetname());
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test clientKill------" << endl;
        redis.clientKill( "127.0.0.1",48019 );
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test clientList------" << endl;
        //redis.clientList(res);
        //cout<<res<<endl;

        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test configGet------" << endl;
        //redis.configGet("s*",vec);
        // print("redis.configGet(s*,vec);",vec);
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test configResetstat-----" << endl;
        //redis.configResetstat();
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test configRewrite------" << endl;
        //print("redis.configRewrite()",redis.configRewrite());
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test configSet------" << endl;
        //print("redis.configSet(slowlog-max-len,1024)",redis.configSet("slowlog-max-len","1024"));
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test dbsize------" << endl;
        //print("redis.dbsize()",redis.dbsize());
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test debugObject------" << endl;
        //print("redis.debugObject(my_pc)",redis.debugObject("my_pc"));
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test debugSegfault------" << endl;
        //redis.debugSegfault();
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test flushall------" << endl;
        //redis.flushall();
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test flushdb------" << endl;
        //redis.flushdb();
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test info------" << endl;
        redis.info(vec);
        print("redis.info(vec)",vec);

        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test lastsave------" << endl;
        //print("redis.lastsave()",redis.lastsave());
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test monitor-----" << endl;
        //redis.monitor();
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test psync------" << endl;
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test save------" << endl;
        //print("redis.save()",redis.save());
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test shutdown------" << endl;
        //print("redis.shutdown()",redis.shutdown());
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test slaveof------" << endl;
        //redis.slaveof("127.0.0.1","6367");
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test slowlog------" << endl;
        vec.clear();
        vec.push_back("LEN");
        redis.slowlog(vec,res);
        cout<<res<<endl;
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test sync------" << endl;
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test time------" << endl;
        string cur,mic;
        redis.time(cur,mic);
        cout<<"redis.time(cur,mic): "<<"cur="<<cur<<",mic="<<mic<<endl;
        //-----------------------------------------------------------------------------------------------------------------------
        cout << "------test finish------" << endl;

    }catch( RdException& e )
    {
        std::cout << "Redis exception:" << e.what() << std::endl;
    }catch( Poco::Exception& e )
    {
        std::cout << "Poco_exception:" << e.what() << std::endl;
    }
}

int main()
{
    CRedisClient redis;
    redis.connect( "127.0.0.1", 6379 );
    VEC  vec;
    // testReadN();
    //TestHash();
    //TestHash2();
    //TestList();
    //TestKey();
    //TestString();
    //TestSet();
    //TestPSub();
   //   TestSortedSet();
    TestServer();

//      TestPSub();
    return 0;
}



