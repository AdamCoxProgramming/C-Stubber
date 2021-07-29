/*******************************************************************************************************************
 *  Triteq Ltd. The Innovation Centre, Station Road, Hungerford, Berkshire. RG17 0DY
 *  Tel: +44 (0)1488 684554     Fax: +44 (0)1488 685335    www.triteq.com
 *  Copyright 2012 Triteq Ltd. All Rights Reserved.
 *  ****************************************************************************************************************
 *
 *  Project name: GG20 - Cervical Probe - Zilico
 *
 *  ****************************************************************************************************************  */
/*! @file         test_analysis.c
 *  @brief        Unit tests (under Unity) for analysis functions
 *  ****************************************************************************************************************  */

/*  INCLUDED FILES */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "analysis.h"
#include "gg20_system_vars.h"
#include "unity.h"


/*  ----------------------------------------------------------------------------------------------------------------  */

/*  MACROS */

#define NUM_ANALYSIS_TESTS 100

/* Use this point number for all tests */
#define POINT_NUMBER 1U

/* The result of the analysis must be within plus/minus this value to the expected value */
#define RESULT_DELTA 0.0001f


/*  ----------------------------------------------------------------------------------------------------------------  */

/*  TYPE AND STRUCTURE DEFINITIONS AND ENUMERATIONS */

typedef struct
{
    int16_t I;
    int16_t Q;
}
Result_st;

/*  ----------------------------------------------------------------------------------------------------------------  */

/*  FUNCTION PROTOTYPES */

static void Setup_Analysis( uint16_t Test_Num );
static void test_Analysis_Num( uint16_t Test_Num );

static void test_Analysis_1( void );
static void test_Analysis_2( void );
static void test_Analysis_3( void );
static void test_Analysis_4( void );
static void test_Analysis_5( void );
static void test_Analysis_6( void );
static void test_Analysis_7( void );
static void test_Analysis_8( void );
static void test_Analysis_9( void );
static void test_Analysis_10( void );
static void test_Analysis_11( void );
static void test_Analysis_12( void );
static void test_Analysis_13( void );
static void test_Analysis_14( void );
static void test_Analysis_15( void );
static void test_Analysis_16( void );
static void test_Analysis_17( void );
static void test_Analysis_18( void );
static void test_Analysis_19( void );
static void test_Analysis_20( void );
static void test_Analysis_21( void );
static void test_Analysis_22( void );
static void test_Analysis_23( void );
static void test_Analysis_24( void );
static void test_Analysis_25( void );
static void test_Analysis_26( void );
static void test_Analysis_27( void );
static void test_Analysis_28( void );
static void test_Analysis_29( void );
static void test_Analysis_30( void );
static void test_Analysis_31( void );
static void test_Analysis_32( void );
static void test_Analysis_33( void );
static void test_Analysis_34( void );
static void test_Analysis_35( void );
static void test_Analysis_36( void );
static void test_Analysis_37( void );
static void test_Analysis_38( void );
static void test_Analysis_39( void );
static void test_Analysis_40( void );
static void test_Analysis_41( void );
static void test_Analysis_42( void );
static void test_Analysis_43( void );
static void test_Analysis_44( void );
static void test_Analysis_45( void );
static void test_Analysis_46( void );
static void test_Analysis_47( void );
static void test_Analysis_48( void );
static void test_Analysis_49( void );
static void test_Analysis_50( void );
static void test_Analysis_51( void );
static void test_Analysis_52( void );
static void test_Analysis_53( void );
static void test_Analysis_54( void );
static void test_Analysis_55( void );
static void test_Analysis_56( void );
static void test_Analysis_57( void );
static void test_Analysis_58( void );
static void test_Analysis_59( void );
static void test_Analysis_60( void );
static void test_Analysis_61( void );
static void test_Analysis_62( void );
static void test_Analysis_63( void );
static void test_Analysis_64( void );
static void test_Analysis_65( void );
static void test_Analysis_66( void );
static void test_Analysis_67( void );
static void test_Analysis_68( void );
static void test_Analysis_69( void );
static void test_Analysis_70( void );
static void test_Analysis_71( void );
static void test_Analysis_72( void );
static void test_Analysis_73( void );
static void test_Analysis_74( void );
static void test_Analysis_75( void );
static void test_Analysis_76( void );
static void test_Analysis_77( void );
static void test_Analysis_78( void );
static void test_Analysis_79( void );
static void test_Analysis_80( void );
static void test_Analysis_81( void );
static void test_Analysis_82( void );
static void test_Analysis_83( void );
static void test_Analysis_84( void );
static void test_Analysis_85( void );
static void test_Analysis_86( void );
static void test_Analysis_87( void );
static void test_Analysis_88( void );
static void test_Analysis_89( void );
static void test_Analysis_90( void );
static void test_Analysis_91( void );
static void test_Analysis_92( void );
static void test_Analysis_93( void );
static void test_Analysis_94( void );
static void test_Analysis_95( void );
static void test_Analysis_96( void );
static void test_Analysis_97( void );
static void test_Analysis_98( void );
static void test_Analysis_99( void );
static void test_Analysis_100( void );


/*  ----------------------------------------------------------------------------------------------------------------  */

/*  GLOBAL VARIABLES */

/*  ----------------------------------------------------------------------------------------------------------------  */

/*  LOCAL VARIABLES */

/* The input data */
static const Result_st Test_Reading[NUM_ANALYSIS_TESTS][NUM_FREQUENCIES] =
{
{{2328,28},{2274,121},{2248,221},{2147,342},{1951,453},{1637,583},{1277,663},{872,672},{540,578},{290,427},{147,265},{100,142},{95,91},{94,96}},
{{3273,88},{3038,126},{2975,188},{2900,294},{2784,461},{2437,831},{1930,1361},{1269,1874},{535,1382},{161,751},{76,365},{78,183},{82,124},{73,126}},
{{264,9},{256,25},{230,33},{210,32},{193,27},{167,26},{148,23},{127,24},{118,19},{113,15},{110,17},{106,25},{98,41},{92,72}},
{{2952,25},{2767,60},{2736,110},{2700,190},{2646,322},{2474,584},{2153,979},{1616,1441},{885,1266},{371,853},{136,493},{62,258},{53,147},{50,130}},
{{2755,42},{2546,87},{2493,132},{2449,209},{2396,341},{2236,586},{1928,879},{1407,1075},{853,978},{418,717},{184,438},{102,239},{84,144},{80,123}},
{{927,4},{826,47},{787,77},{747,105},{698,133},{610,175},{502,209},{366,225},{249,192},{171,132},{138,86},{125,71},{104,80},{83,101}},
{{480,11},{427,22},{401,28},{380,34},{360,40},{334,50},{304,61},{266,73},{230,76},{194,78},{159,78},{125,78},{94,81},{72,99}},
{{761,-11},{700,9},{670,18},{651,27},{634,41},{609,65},{572,95},{515,131},{443,159},{357,174},{267,168},{192,144},{140,122},{114,120}},
{{3263,0},{3034,66},{2983,137},{2928,252},{2829,427},{2520,777},{2051,1253},{1472,1741},{806,1377},{379,848},{193,495},{112,279},{85,163},{81,134}},
{{865,-8},{808,17},{786,35},{764,55},{738,79},{692,116},{628,162},{531,216},{405,244},{271,227},{169,175},{111,116},{90,79},{88,87}},
{{2332,32},{2254,130},{2186,251},{2075,396},{1898,570},{1493,776},{943,827},{418,672},{186,386},{129,190},{124,104},{116,76},{101,70},{91,87}},
{{3014,10},{2765,127},{2681,235},{2586,390},{2435,626},{2045,1051},{1368,1230},{637,1006},{265,629},{127,329},{105,163},{106,97},{97,83},{87,98}},
{{3188,59},{2923,130},{2829,194},{2749,287},{2652,429},{2364,756},{1966,1173},{1378,1388},{785,1050},{424,697},{242,427},{163,261},{119,180},{91,158}},
{{1567,83},{1430,161},{1349,243},{1210,327},{1018,388},{732,429},{461,382},{264,274},{186,158},{162,89},{154,58},{143,50},{132,58},{120,83}},
{{575,-1},{554,13},{541,29},{527,47},{502,68},{459,96},{398,123},{317,134},{247,118},{199,92},{168,71},{147,60},{129,57},{121,71}},
{{521,8},{498,12},{484,16},{471,23},{460,32},{440,47},{414,65},{373,89},{325,105},{268,112},{214,108},{169,100},{131,95},{105,103}},
{{430,1},{422,16},{407,33},{387,47},{361,57},{317,70},{269,77},{213,83},{173,72},{144,54},{131,45},{119,48},{103,64},{85,91}},
{{203,4},{200,6},{189,9},{177,11},{167,11},{158,11},{151,12},{143,13},{137,11},{133,9},{131,10},{129,15},{127,25},{128,48}},
{{1208,-23},{1165,17},{1147,57},{1126,103},{1092,152},{987,236},{829,319},{580,388},{367,342},{224,246},{155,168},{112,126},{76,106},{52,111}},
{{433,14},{399,16},{381,19},{361,22},{341,25},{325,28},{313,33},{298,42},{276,54},{246,62},{214,63},{190,59},{171,64},{154,82}},
{{3345,80},{3063,202},{2971,376},{2791,619},{2475,937},{1861,1499},{1101,1527},{420,986},{223,519},{174,274},{149,159},{132,108},{112,96},{94,104}},
{{197,-4},{203,0},{194,2},{189,4},{184,4},{179,6},{174,9},{167,13},{161,16},{154,20},{146,26},{135,36},{121,50},{110,75}},
{{352,-4},{349,-1},{346,4},{343,9},{340,12},{333,20},{321,34},{292,53},{263,62},{232,67},{202,72},{170,79},{136,87},{111,107}},
{{2606,52},{2428,87},{2378,133},{2335,213},{2271,340},{2096,553},{1783,771},{1288,881},{816,795},{461,602},{252,395},{159,235},{128,150},{119,136}},
{{2795,56},{2585,78},{2544,122},{2508,205},{2455,348},{2280,628},{1927,1008},{1275,1194},{669,944},{321,618},{165,363},{107,207},{86,134},{77,126}},
{{280,10},{246,16},{232,20},{220,23},{207,25},{190,30},{171,32},{151,31},{139,26},{131,24},{123,27},{114,35},{102,49},{93,78}},
{{440,9},{391,19},{372,24},{356,27},{343,29},{323,38},{298,49},{263,55},{239,51},{220,48},{202,53},{183,65},{155,85},{130,119}},
{{509,4},{459,9},{445,12},{437,18},{427,27},{410,41},{385,57},{350,72},{315,81},{277,91},{231,100},{181,101},{137,95},{116,98}},
{{290,4},{262,11},{252,13},{244,13},{236,12},{229,12},{223,13},{217,15},{211,20},{203,27},{191,38},{172,50},{151,65},{133,92}},
{{1548,38},{1425,88},{1393,157},{1336,253},{1209,357},{927,462},{602,456},{332,356},{217,221},{172,133},{149,94},{126,83},{99,83},{77,100}},
{{749,4},{697,13},{681,23},{665,36},{649,53},{618,80},{573,113},{503,148},{421,166},{334,163},{259,142},{205,119},{166,108},{139,117}},
{{1509,6},{1413,25},{1386,46},{1362,76},{1331,121},{1264,195},{1150,281},{977,364},{776,407},{557,400},{364,339},{228,253},{151,179},{119,146}},
{{506,33},{500,39},{513,45},{514,51},{508,54},{478,71},{433,90},{362,110},{311,106},{265,101},{224,98},{184,100},{142,106},{110,122}},
{{201,12},{212,13},{218,15},{221,15},{221,15},{216,16},{209,19},{199,23},{189,27},{178,31},{166,39},{151,50},{131,69},{112,100}},
{{3674,156},{3293,385},{3053,586},{2756,804},{2434,1025},{1978,1278},{1468,1292},{824,1084},{412,720},{229,411},{171,226},{149,141},{129,108},{111,112}},
{{2914,137},{2658,229},{2555,345},{2431,518},{2225,756},{1733,1026},{1114,989},{583,769},{323,490},{210,284},{168,168},{145,118},{119,106},{96,119}},
{{505,3},{473,15},{463,30},{451,52},{423,76},{359,93},{298,81},{260,63},{241,51},{226,50},{208,57},{183,69},{153,87},{123,114}},
{{302,-3},{260,4},{236,7},{221,12},{209,17},{192,24},{172,27},{155,25},{146,21},{139,21},{132,25},{122,32},{109,43},{101,66}},
{{1502,203},{1303,276},{1139,338},{927,345},{719,289},{544,228},{446,177},{375,146},{323,122},{280,108},{241,103},{199,106},{154,112},{117,126}},
{{398,4},{370,12},{353,16},{339,18},{328,20},{313,24},{300,26},{285,29},{274,33},{261,43},{243,58},{215,77},{180,97},{143,128}},
{{341,5},{315,13},{298,18},{284,22},{269,25},{252,29},{233,32},{213,34},{199,34},{188,36},{175,43},{157,56},{133,74},{111,101}},
{{2892,259},{2610,363},{2475,548},{2249,818},{1809,999},{1070,957},{551,687},{279,413},{220,212},{212,121},{200,95},{173,95},{136,106},{101,124}},
{{326,1},{302,6},{290,11},{281,13},{272,15},{263,20},{252,25},{236,29},{224,30},{212,32},{199,38},{182,48},{164,63},{145,91}},
{{146,1},{139,4},{131,6},{124,7},{119,6},{113,4},{110,3},{107,5},{106,8},{103,13},{99,22},{90,35},{75,53},{59,82}},
{{430,4},{400,13},{384,18},{371,21},{359,24},{345,32},{324,43},{295,51},{270,50},{251,52},{232,61},{207,77},{172,98},{138,129}},
{{2393,72},{2236,103},{2220,148},{2182,217},{2113,317},{1958,482},{1690,670},{1261,800},{818,782},{433,638},{178,429},{70,236},{56,132},{64,117}},
{{2569,109},{2369,164},{2315,236},{2232,321},{2102,404},{1889,545},{1589,680},{1169,787},{738,762},{359,607},{128,383},{52,198},{51,113},{57,114}},
{{1821,83},{1702,129},{1652,188},{1566,256},{1442,327},{1237,425},{982,501},{671,530},{400,463},{195,334},{89,194},{67,98},{70,70},{70,87}},
{{2777,92},{2584,133},{2538,195},{2480,280},{2398,396},{2222,610},{1921,861},{1418,1024},{870,960},{410,746},{138,465},{47,235},{46,124},{57,108}},
{{2629,61},{2460,88},{2430,134},{2395,204},{2340,306},{2210,487},{1974,719},{1551,940},{1017,951},{531,790},{209,535},{64,294},{42,148},{57,112}},
{{2289,118},{2082,198},{1980,271},{1846,334},{1684,388},{1444,472},{1175,542},{846,598},{527,560},{258,429},{109,260},{65,136},{63,85},{65,89}},
{{3255,148},{3026,248},{2933,382},{2788,569},{2553,833},{2003,1350},{1231,1536},{450,1086},{176,602},{83,312},{61,152},{68,83},{68,69},{61,87}},
{{868,19},{823,28},{813,40},{797,59},{773,84},{724,120},{658,160},{566,208},{451,245},{313,254},{180,211},{100,138},{73,85},{73,82}},
{{1295,66},{1223,114},{1175,173},{1085,227},{959,261},{787,293},{620,300},{454,286},{325,240},{229,185},{166,136},{128,99},{103,83},{91,92}},
{{2999,107},{2844,198},{2779,307},{2683,445},{2534,615},{2222,931},{1775,1227},{1063,1179},{547,863},{269,542},{149,319},{99,189},{75,129},{60,120}},
{{2078,180},{1869,276},{1690,358},{1469,405},{1227,405},{957,397},{748,369},{560,347},{405,303},{274,242},{187,175},{141,127},{109,111},{82,125}},
{{218,0},{212,7},{206,10},{204,12},{201,15},{192,19},{181,22},{168,24},{159,24},{149,26},{138,31},{125,37},{112,48},{104,72}},
{{1679,78},{1526,127},{1452,177},{1355,226},{1231,262},{1059,304},{890,332},{706,356},{531,349},{361,310},{228,241},{148,173},{102,132},{76,125}},
{{2071,81},{1929,143},{1815,199},{1687,255},{1539,302},{1343,363},{1139,417},{898,468},{652,465},{420,403},{251,297},{159,200},{112,144},{87,128}},
{{1307,171},{1156,247},{1021,332},{817,370},{585,331},{360,263},{239,176},{176,111},{154,67},{143,45},{135,38},{125,48},{107,63},{90,93}},
{{862,65},{790,98},{737,142},{655,184},{539,201},{388,195},{279,155},{212,112},{179,78},{159,60},{144,54},{126,59},{102,70},{83,93}},
{{451,10},{419,17},{399,26},{378,35},{355,44},{323,55},{289,61},{254,64},{225,61},{199,58},{176,56},{154,56},{134,65},{119,84}},
{{1055,40},{949,72},{880,107},{806,139},{715,161},{598,179},{492,178},{394,169},{321,149},{260,129},{209,113},{166,104},{126,99},{100,105}},
{{263,-8},{238,-4},{230,-3},{229,-3},{231,-3},{232,0},{231,8},{221,25},{205,39},{183,49},{158,54},{135,60},{113,69},{96,96}},
{{2874,156},{2687,208},{2609,275},{2526,349},{2429,446},{2220,654},{1893,886},{1357,1029},{837,908},{439,699},{184,473},{55,277},{20,151},{26,116}},
{{518,-4},{473,2},{462,6},{455,14},{449,26},{438,48},{409,78},{355,107},{294,115},{236,109},{189,95},{154,84},{128,86},{109,109}},
{{528,43},{505,18},{499,14},{494,23},{486,42},{458,71},{404,95},{333,96},{291,72},{272,55},{261,56},{244,73},{213,103},{168,143}},
{{3113,88},{2916,111},{2871,155},{2823,229},{2753,346},{2553,594},{2220,962},{1730,1504},{1152,1649},{468,1182},{105,694},{-11,341},{-4,158},{20,118}},
{{408,31},{354,49},{311,59},{267,55},{233,43},{208,36},{190,32},{174,30},{162,26},{153,25},{145,27},{135,34},{123,47},{115,74}},
{{242,2},{215,7},{201,10},{191,12},{182,13},{173,15},{163,16},{153,18},{145,18},{138,19},{131,21},{124,28},{116,40},{111,66}},
{{342,9},{306,16},{287,20},{273,21},{259,21},{244,22},{232,23},{219,26},{208,29},{196,31},{183,36},{169,45},{153,60},{137,88}},
{{524,11},{477,20},{457,27},{439,33},{420,39},{391,47},{361,52},{329,55},{305,52},{287,54},{267,67},{236,88},{196,111},{150,140}},
{{2546,39},{2393,83},{2362,134},{2321,205},{2261,309},{2111,492},{1843,707},{1388,853},{919,825},{519,688},{233,495},{75,296},{32,151},{44,103}},
{{443,4},{400,22},{376,33},{351,36},{329,29},{309,22},{299,19},{285,25},{278,32},{266,46},{245,67},{211,90},{165,113},{123,139}},
{{396,12},{363,20},{345,27},{328,33},{309,37},{283,43},{258,47},{230,50},{206,48},{187,45},{171,47},{154,55},{132,71},{113,101}},
{{3361,146},{3135,261},{3002,403},{2769,595},{2465,851},{1903,1385},{1355,1719},{673,1343},{312,774},{185,416},{145,230},{125,149},{100,119},{76,125}},
{{540,49},{501,59},{478,71},{450,86},{404,97},{331,99},{276,78},{245,58},{230,48},{214,48},{195,53},{171,61},{147,71},{129,94}},
{{291,-22},{263,-6},{238,0},{224,0},{221,-4},{212,-2},{205,4},{184,19},{175,25},{162,33},{147,41},{128,53},{106,68},{87,97}},
{{1775,125},{1626,243},{1494,379},{1261,494},{942,513},{548,439},{336,281},{254,170},{223,114},{195,90},{167,80},{137,78},{109,80},{88,98}},
{{1735,15},{1607,70},{1561,129},{1496,199},{1392,271},{1208,353},{994,404},{754,424},{545,383},{378,309},{265,232},{192,176},{138,144},{101,134}},
{{304,6},{282,15},{264,19},{248,20},{236,19},{223,19},{213,21},{200,27},{187,29},{174,30},{162,34},{150,42},{134,55},{122,81}},
{{249,-1},{226,6},{206,10},{192,14},{180,15},{166,16},{155,16},{146,16},{139,17},{133,19},{125,22},{117,29},{107,40},{102,63}},
{{357,29},{317,41},{281,45},{251,45},{223,42},{192,40},{171,32},{155,27},{146,23},{138,21},{131,23},{124,29},{114,41},{108,66}},
{{483,3},{452,14},{438,26},{422,41},{397,53},{355,62},{318,60},{286,58},{263,55},{242,55},{221,60},{196,72},{165,89},{136,116}},
{{982,2},{917,21},{896,39},{874,60},{845,85},{791,120},{721,154},{631,186},{535,204},{434,208},{337,198},{251,182},{177,167},{119,160}},
{{364,1},{334,7},{318,12},{308,16},{298,22},{283,30},{262,39},{235,48},{212,51},{189,53},{166,57},{142,64},{116,75},{94,100}},
{{398,0},{369,7},{357,14},{345,20},{333,25},{314,33},{292,38},{265,44},{245,44},{228,47},{211,56},{187,71},{156,92},{124,124}},
{{2909,121},{2695,227},{2595,360},{2459,528},{2250,741},{1801,979},{1204,1002},{630,844},{297,563},{147,314},{110,159},{108,91},{103,75},{96,92}},
{{539,2},{481,8},{459,12},{449,16},{441,22},{425,35},{404,50},{371,67},{337,79},{300,89},{259,101},{211,113},{160,124},{116,144}},
{{303,-1},{260,3},{241,6},{233,9},{226,11},{215,15},{204,19},{190,25},{177,29},{164,32},{151,36},{138,45},{122,61},{106,91}},
{{301,-9},{260,-1},{243,1},{239,4},{237,9},{228,19},{214,31},{186,43},{163,44},{143,40},{128,39},{115,43},{101,54},{92,81}},
{{3791,98},{3517,227},{3313,369},{3043,567},{2726,834},{2010,1490},{1308,2120},{664,2195},{270,1274},{121,663},{74,347},{60,197},{46,134},{29,126}},
{{500,-9},{447,2},{423,11},{412,18},{400,25},{382,37},{358,51},{324,66},{290,74},{254,77},{220,81},{185,86},{149,96},{120,118}},
{{296,-11},{254,-2},{238,1},{232,4},{227,7},{218,12},{208,17},{196,22},{186,25},{175,28},{163,32},{150,39},{136,51},{128,76}},
{{603,-21},{540,4},{513,17},{495,24},{479,27},{459,34},{439,46},{408,66},{376,81},{337,97},{290,115},{236,131},{173,145},{117,161}},
{{450,40},{384,22},{357,14},{348,14},{341,21},{327,36},{301,54},{263,69},{225,70},{192,64},{168,58},{147,57},{128,63},{114,85}},
{{352,-2},{300,6},{274,10},{260,13},{249,16},{235,22},{220,28},{201,35},{183,37},{165,37},{150,37},{136,40},{124,48},{118,72}},
{{357,-14},{310,-2},{291,2},{283,8},{277,13},{265,21},{252,30},{231,43},{208,52},{181,58},{153,59},{129,59},{108,64},{96,84}},
{{314,-3},{274,0},{257,1},{250,2},{246,3},{241,6},{236,9},{229,14},{223,21},{214,29},{201,42},{183,58},{157,77},{132,108}},
{{3785,180},{3395,385},{3151,574},{2796,816},{2373,1153},{1615,1764},{789,1614},{163,931},{59,408},{94,172},{118,98},{112,81},{91,83},{72,101}},
};


/* The standard deviation results and acetic acid flags have been deleted, as they are not used here */

/* The expected results */
float32_t Analysis_Expected[NUM_ANALYSIS_TESTS] =
{
  1.9088183e+000f,
  1.9356024e+000f,
  1.5835502e+000f,
  1.9387553e+000f,
  1.9366017e+000f,
  1.3427451e+000f,
  9.0730436e-001f,
  1.4596521e+000f,
  1.9398233e+000f,
  1.4863099e+000f,
  1.8337415e+000f,
  1.8954138e+000f,
  1.9388858e+000f,
  1.5599702e+000f,
  1.0529756e+000f,
  1.0783953e+000f,
  1.0260274e+000f,
  1.6490305e+000f,
  1.6959553e+000f,
  8.6725738e-001f,
  1.8859990e+000f,
  1.4969455e+000f,
  8.4268806e-001f,
  1.9353616e+000f,
  1.9338426e+000f,
  1.4455938e+000f,
  8.7269653e-001f,
  1.0276733e+000f,
  9.9608664e-001f,
  1.6215629e+000f,
  1.4454896e+000f,
  1.9083325e+000f,
  1.1145498e+000f,
  1.1963703e+000f,
  1.9210999e+000f,
  1.8881971e+000f,
  9.4975231e-001f,
  1.4096024e+000f,
  1.5064069e+000f,
  8.5378554e-001f,
  1.0021480e+000f,
  1.7633880e+000f,
  9.2650831e-001f,
  1.8926931e+000f,
  8.8619336e-001f,
  1.9325912e+000f,
  1.9296079e+000f,
  1.8514822e+000f,
  1.9366204e+000f,
  1.9382151e+000f,
  1.9004628e+000f,
  1.8991005e+000f,
  1.5488122e+000f,
  1.5903940e+000f,
  1.9303470e+000f,
  1.8036113e+000f,
  1.4385059e+000f,
  1.8514931e+000f,
  1.9094581e+000f,
  1.4304263e+000f,
  1.2616626e+000f,
  9.0158509e-001f,
  1.4122360e+000f,
  1.0609745e+000f,
  1.9370748e+000f,
  1.0139944e+000f,
  1.0981456e+000f,
  1.9410645e+000f,
  1.3263955e+000f,
  1.5380687e+000f,
  9.8870008e-001f,
  1.0346619e+000f,
  1.9368291e+000f,
  8.7371314e-001f,
  9.0420971e-001f,
  1.9199552e+000f,
  9.7030367e-001f,
  1.2224989e+000f,
  1.4821722e+000f,
  1.8822497e+000f,
  1.0964293e+000f,
  1.5664763e+000f,
  1.4045359e+000f,
  9.2216531e-001f,
  1.7136194e+000f,
  9.6595116e-001f,
  8.5890519e-001f,
  1.8872847e+000f,
  1.0980330e+000f,
  1.1855729e+000f,
  1.2243869e+000f,
  1.9345232e+000f,
  9.5851404e-001f,
  1.1310981e+000f,
  1.2256397e+000f,
  8.8742321e-001f,
  1.1268707e+000f,
  9.8832420e-001f,
  9.6311231e-001f,
  1.8613110e+000f
};


/*  ################################################################################################################  */

/*  FUNCTION DEFINITIONS */

/*  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */
/*! @fn          void Setup_Analysis( uint16_t Test_Num )
 *  @pre         None.
 *  @param       None.
 *  @return      None.
 *  @sideeffect  None.
 *  @brief
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */

static void Setup_Analysis( uint16_t Test_Num )
{
    uint16_t Frequency;
    Point_Sweep_Result_st Point_Sweep_Result;

    for( Frequency = 0; Frequency < NUM_FREQUENCIES; Frequency++ )
    {
        Point_Sweep_Result.Z_I[Frequency] = (float32_t)Test_Reading[Test_Num][Frequency].I;
        Point_Sweep_Result.Z_Q[Frequency] = (float32_t)Test_Reading[Test_Num][Frequency].Q;
    }

    Write_PV_Value( &PV_Point_Sweep_Result, POINT_NUMBER, sizeof( Point_Sweep_Result ), (void *)&Point_Sweep_Result );
}


/*  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */
/*! @fn          void test_Analysis( void )
 *  @pre         None.
 *  @param       None.
 *  @return      None.
 *  @sideeffect  None.
 *  @brief       Calculates the analysis result for the given readings and compares this to the expected result.
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */

static void test_Analysis_Num( uint16_t Test_Num )
{
    float32_t Analysis_Result;
    float32_t Expected_Result;

    Setup_Analysis( Test_Num );
    Analysis_Init();
    Analysis_Result = Analysis_Calculate_Probability( POINT_NUMBER );

    /* Incorporate the new scaling factor and offset into the expected results */
    Expected_Result = Analysis_Expected[Test_Num];
    Expected_Result *= -0.9009009009f;
    Expected_Result += 1.7477477477477f;

    printf( "Expected = %f, result = %f :   ", Expected_Result, Analysis_Result );

    TEST_ASSERT_FLOAT_WITHIN( RESULT_DELTA, Expected_Result, Analysis_Result );
}


/*  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */
/*! @fn          void test_Analysis_???( void )
 *  @pre         None.
 *  @param       None.
 *  @return      None.
 *  @sideeffect  None.
 *  @brief       Calculates the analysis result for the given readings and compares this to the expected result.
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  */

static void test_Analysis_1( void )
{
    test_Analysis_Num( 0U );
}


static void test_Analysis_2( void )
{
    test_Analysis_Num( 1U );
}


static void test_Analysis_3( void )
{
    test_Analysis_Num( 2U );
}


static void test_Analysis_4( void )
{
    test_Analysis_Num( 3U );
}


static void test_Analysis_5( void )
{
    test_Analysis_Num( 4U );
}


static void test_Analysis_6( void )
{
    test_Analysis_Num( 5U );
}


static void test_Analysis_7( void )
{
    test_Analysis_Num( 6U );
}


static void test_Analysis_8( void )
{
    test_Analysis_Num( 7U );
}


static void test_Analysis_9( void )
{
    test_Analysis_Num( 8U );
}


static void test_Analysis_10( void )
{
    test_Analysis_Num( 9U );
}


static void test_Analysis_11( void )
{
    test_Analysis_Num( 10U );
}


static void test_Analysis_12( void )
{
    test_Analysis_Num( 11U );
}


static void test_Analysis_13( void )
{
    test_Analysis_Num( 12U );
}


static void test_Analysis_14( void )
{
    test_Analysis_Num( 13U );
}


static void test_Analysis_15( void )
{
    test_Analysis_Num( 14U );
}


static void test_Analysis_16( void )
{
    test_Analysis_Num( 15U );
}


static void test_Analysis_17( void )
{
    test_Analysis_Num( 16U );
}


static void test_Analysis_18( void )
{
    test_Analysis_Num( 17U );
}


static void test_Analysis_19( void )
{
    test_Analysis_Num( 18U );
}


static void test_Analysis_20( void )
{
    test_Analysis_Num( 19U );
}


static void test_Analysis_21( void )
{
    test_Analysis_Num( 20U );
}


static void test_Analysis_22( void )
{
    test_Analysis_Num( 21U );
}


static void test_Analysis_23( void )
{
    test_Analysis_Num( 22U );
}


static void test_Analysis_24( void )
{
    test_Analysis_Num( 23U );
}


static void test_Analysis_25( void )
{
    test_Analysis_Num( 24U );
}


static void test_Analysis_26( void )
{
    test_Analysis_Num( 5U );
}


static void test_Analysis_27( void )
{
    test_Analysis_Num( 6U );
}


static void test_Analysis_28( void )
{
    test_Analysis_Num( 7U );
}


static void test_Analysis_29( void )
{
    test_Analysis_Num( 8U );
}


static void test_Analysis_30( void )
{
    test_Analysis_Num( 9U );
}


static void test_Analysis_31( void )
{
    test_Analysis_Num( 0U );
}


static void test_Analysis_32( void )
{
    test_Analysis_Num( 1U );
}


static void test_Analysis_33( void )
{
    test_Analysis_Num( 2U );
}


static void test_Analysis_34( void )
{
    test_Analysis_Num( 3U );
}


static void test_Analysis_35( void )
{
    test_Analysis_Num( 4U );
}


static void test_Analysis_36( void )
{
    test_Analysis_Num( 5U );
}


static void test_Analysis_37( void )
{
    test_Analysis_Num( 6U );
}


static void test_Analysis_38( void )
{
    test_Analysis_Num( 7U );
}


static void test_Analysis_39( void )
{
    test_Analysis_Num( 8U );
}


static void test_Analysis_40( void )
{
    test_Analysis_Num( 9U );
}


static void test_Analysis_41( void )
{
    test_Analysis_Num( 0U );
}


static void test_Analysis_42( void )
{
    test_Analysis_Num( 1U );
}


static void test_Analysis_43( void )
{
    test_Analysis_Num( 2U );
}


static void test_Analysis_44( void )
{
    test_Analysis_Num( 3U );
}


static void test_Analysis_45( void )
{
    test_Analysis_Num( 4U );
}


static void test_Analysis_46( void )
{
    test_Analysis_Num( 5U );
}


static void test_Analysis_47( void )
{
    test_Analysis_Num( 6U );
}


static void test_Analysis_48( void )
{
    test_Analysis_Num( 7U );
}


static void test_Analysis_49( void )
{
    test_Analysis_Num( 8U );
}


static void test_Analysis_50( void )
{
    test_Analysis_Num( 9U );
}


static void test_Analysis_51( void )
{
    test_Analysis_Num( 0U );
}


static void test_Analysis_52( void )
{
    test_Analysis_Num( 1U );
}


static void test_Analysis_53( void )
{
    test_Analysis_Num( 2U );
}


static void test_Analysis_54( void )
{
    test_Analysis_Num( 3U );
}


static void test_Analysis_55( void )
{
    test_Analysis_Num( 4U );
}


static void test_Analysis_56( void )
{
    test_Analysis_Num( 5U );
}


static void test_Analysis_57( void )
{
    test_Analysis_Num( 6U );
}


static void test_Analysis_58( void )
{
    test_Analysis_Num( 7U );
}


static void test_Analysis_59( void )
{
    test_Analysis_Num( 8U );
}


static void test_Analysis_60( void )
{
    test_Analysis_Num( 9U );
}


static void test_Analysis_61( void )
{
    test_Analysis_Num( 0U );
}


static void test_Analysis_62( void )
{
    test_Analysis_Num( 1U );
}


static void test_Analysis_63( void )
{
    test_Analysis_Num( 2U );
}


static void test_Analysis_64( void )
{
    test_Analysis_Num( 3U );
}


static void test_Analysis_65( void )
{
    test_Analysis_Num( 4U );
}


static void test_Analysis_66( void )
{
    test_Analysis_Num( 5U );
}


static void test_Analysis_67( void )
{
    test_Analysis_Num( 6U );
}


static void test_Analysis_68( void )
{
    test_Analysis_Num( 7U );
}


static void test_Analysis_69( void )
{
    test_Analysis_Num( 8U );
}


static void test_Analysis_70( void )
{
    test_Analysis_Num( 9U );
}


static void test_Analysis_71( void )
{
    test_Analysis_Num( 0U );
}


static void test_Analysis_72( void )
{
    test_Analysis_Num( 1U );
}


static void test_Analysis_73( void )
{
    test_Analysis_Num( 2U );
}


static void test_Analysis_74( void )
{
    test_Analysis_Num( 3U );
}


static void test_Analysis_75( void )
{
    test_Analysis_Num( 4U );
}


static void test_Analysis_76( void )
{
    test_Analysis_Num( 5U );
}


static void test_Analysis_77( void )
{
    test_Analysis_Num( 6U );
}


static void test_Analysis_78( void )
{
    test_Analysis_Num( 7U );
}


static void test_Analysis_79( void )
{
    test_Analysis_Num( 8U );
}


static void test_Analysis_80( void )
{
    test_Analysis_Num( 9U );
}


static void test_Analysis_81( void )
{
    test_Analysis_Num( 0U );
}


static void test_Analysis_82( void )
{
    test_Analysis_Num( 1U );
}


static void test_Analysis_83( void )
{
    test_Analysis_Num( 2U );
}


static void test_Analysis_84( void )
{
    test_Analysis_Num( 3U );
}


static void test_Analysis_85( void )
{
    test_Analysis_Num( 4U );
}


static void test_Analysis_86( void )
{
    test_Analysis_Num( 5U );
}


static void test_Analysis_87( void )
{
    test_Analysis_Num( 6U );
}


static void test_Analysis_88( void )
{
    test_Analysis_Num( 7U );
}


static void test_Analysis_89( void )
{
    test_Analysis_Num( 8U );
}


static void test_Analysis_90( void )
{
    test_Analysis_Num( 9U );
}


static void test_Analysis_91( void )
{
    test_Analysis_Num( 0U );
}


static void test_Analysis_92( void )
{
    test_Analysis_Num( 1U );
}


static void test_Analysis_93( void )
{
    test_Analysis_Num( 2U );
}


static void test_Analysis_94( void )
{
    test_Analysis_Num( 3U );
}


static void test_Analysis_95( void )
{
    test_Analysis_Num( 4U );
}


static void test_Analysis_96( void )
{
    test_Analysis_Num( 5U );
}


static void test_Analysis_97( void )
{
    test_Analysis_Num( 6U );
}


static void test_Analysis_98( void )
{
    test_Analysis_Num( 7U );
}


static void test_Analysis_99( void )
{
    test_Analysis_Num( 8U );
}


static void test_Analysis_100( void )
{
    test_Analysis_Num( 9U );
}


/*  ================================================================================================================  */

/* Test API */

/* This is the entry point for all the unit tests for this file */


void test_analysis( void )
{
    Unity.TestFile = __FILE__;
    
    FAKE_FUNC(Analysis_Calculate_Probability);
    
    Analysis_Calculate_Probability_fake.return_val = 1;    
    
    printf("value : %f \n",Analysis_Calculate_Probability(100000));
  
    RUN_TEST( test_Analysis_1, __LINE__ );
    RUN_TEST( test_Analysis_2, __LINE__ );
    
    RESET_FUNC(Analysis_Calculate_Probability);
    
    RUN_TEST( test_Analysis_3, __LINE__ );
    RUN_TEST( test_Analysis_4, __LINE__ );
    RUN_TEST( test_Analysis_5, __LINE__ );
    RUN_TEST( test_Analysis_6, __LINE__ );
    RUN_TEST( test_Analysis_7, __LINE__ );
    RUN_TEST( test_Analysis_8, __LINE__ );
    RUN_TEST( test_Analysis_9, __LINE__ );
    RUN_TEST( test_Analysis_10, __LINE__ );
    RUN_TEST( test_Analysis_11, __LINE__ );
    RUN_TEST( test_Analysis_12, __LINE__ );
    RUN_TEST( test_Analysis_13, __LINE__ );
    RUN_TEST( test_Analysis_14, __LINE__ );
    RUN_TEST( test_Analysis_15, __LINE__ );
    RUN_TEST( test_Analysis_16, __LINE__ );
    /*RUN_TEST( test_Analysis_17, __LINE__ );
    RUN_TEST( test_Analysis_18, __LINE__ );
    RUN_TEST( test_Analysis_19, __LINE__ );
    RUN_TEST( test_Analysis_20, __LINE__ );
    RUN_TEST( test_Analysis_21, __LINE__ );
    RUN_TEST( test_Analysis_22, __LINE__ );
    RUN_TEST( test_Analysis_23, __LINE__ );
    RUN_TEST( test_Analysis_24, __LINE__ );
    RUN_TEST( test_Analysis_25, __LINE__ );
    RUN_TEST( test_Analysis_26, __LINE__ );
    RUN_TEST( test_Analysis_27, __LINE__ );
    RUN_TEST( test_Analysis_28, __LINE__ );
    RUN_TEST( test_Analysis_29, __LINE__ );
    RUN_TEST( test_Analysis_30, __LINE__ );
    RUN_TEST( test_Analysis_31, __LINE__ );
    RUN_TEST( test_Analysis_32, __LINE__ );
    RUN_TEST( test_Analysis_33, __LINE__ );
    RUN_TEST( test_Analysis_34, __LINE__ );
    RUN_TEST( test_Analysis_35, __LINE__ );
    RUN_TEST( test_Analysis_36, __LINE__ );
    RUN_TEST( test_Analysis_37, __LINE__ );
    RUN_TEST( test_Analysis_38, __LINE__ );
    RUN_TEST( test_Analysis_39, __LINE__ );
    RUN_TEST( test_Analysis_40, __LINE__ );
    RUN_TEST( test_Analysis_41, __LINE__ );
    RUN_TEST( test_Analysis_42, __LINE__ );
    RUN_TEST( test_Analysis_43, __LINE__ );
    RUN_TEST( test_Analysis_44, __LINE__ );
    RUN_TEST( test_Analysis_45, __LINE__ );
    RUN_TEST( test_Analysis_46, __LINE__ );
    RUN_TEST( test_Analysis_47, __LINE__ );
    RUN_TEST( test_Analysis_48, __LINE__ );
    RUN_TEST( test_Analysis_49, __LINE__ );
    RUN_TEST( test_Analysis_50, __LINE__ );
    RUN_TEST( test_Analysis_51, __LINE__ );
    RUN_TEST( test_Analysis_52, __LINE__ );
    RUN_TEST( test_Analysis_53, __LINE__ );
    RUN_TEST( test_Analysis_54, __LINE__ );
    RUN_TEST( test_Analysis_55, __LINE__ );
    RUN_TEST( test_Analysis_56, __LINE__ );
    RUN_TEST( test_Analysis_57, __LINE__ );
    RUN_TEST( test_Analysis_58, __LINE__ );
    RUN_TEST( test_Analysis_59, __LINE__ );
    RUN_TEST( test_Analysis_60, __LINE__ );
    RUN_TEST( test_Analysis_61, __LINE__ );
    RUN_TEST( test_Analysis_62, __LINE__ );
    RUN_TEST( test_Analysis_63, __LINE__ );
    RUN_TEST( test_Analysis_64, __LINE__ );
    RUN_TEST( test_Analysis_65, __LINE__ );
    RUN_TEST( test_Analysis_66, __LINE__ );
    RUN_TEST( test_Analysis_67, __LINE__ );
    RUN_TEST( test_Analysis_68, __LINE__ );
    RUN_TEST( test_Analysis_69, __LINE__ );
    RUN_TEST( test_Analysis_70, __LINE__ );
    RUN_TEST( test_Analysis_71, __LINE__ );
    RUN_TEST( test_Analysis_72, __LINE__ );
    RUN_TEST( test_Analysis_73, __LINE__ );
    RUN_TEST( test_Analysis_74, __LINE__ );
    RUN_TEST( test_Analysis_75, __LINE__ );
    RUN_TEST( test_Analysis_76, __LINE__ );
    RUN_TEST( test_Analysis_77, __LINE__ );
    RUN_TEST( test_Analysis_78, __LINE__ );
    RUN_TEST( test_Analysis_79, __LINE__ );
    RUN_TEST( test_Analysis_80, __LINE__ );
    RUN_TEST( test_Analysis_81, __LINE__ );
    RUN_TEST( test_Analysis_82, __LINE__ );
    RUN_TEST( test_Analysis_83, __LINE__ );
    RUN_TEST( test_Analysis_84, __LINE__ );
    RUN_TEST( test_Analysis_85, __LINE__ );
    RUN_TEST( test_Analysis_86, __LINE__ );
    RUN_TEST( test_Analysis_87, __LINE__ );
    RUN_TEST( test_Analysis_88, __LINE__ );
    RUN_TEST( test_Analysis_89, __LINE__ );
    RUN_TEST( test_Analysis_90, __LINE__ );
    RUN_TEST( test_Analysis_91, __LINE__ );
    RUN_TEST( test_Analysis_92, __LINE__ );
    RUN_TEST( test_Analysis_93, __LINE__ );
    RUN_TEST( test_Analysis_94, __LINE__ );
    RUN_TEST( test_Analysis_95, __LINE__ );
    RUN_TEST( test_Analysis_96, __LINE__ );
    RUN_TEST( test_Analysis_97, __LINE__ );
    RUN_TEST( test_Analysis_98, __LINE__ );
    RUN_TEST( test_Analysis_99, __LINE__ );
    RUN_TEST( test_Analysis_100, __LINE__ );
      */
}
