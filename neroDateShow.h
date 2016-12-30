
 struct ActivationNeuron;
typedef struct ActivationNeuron  NeuronObject;
typedef struct ActivationNeuron ActNero;
 typedef struct NerveFiber_ NerveFiber;




 struct ActivationNeuron
{
nero_us32int msg;/*记录该nero的种类，性质等信息*/
nero_s32int x;/*取值范围-2147483648 ~ 2147483647       use x  to  recond  how many chind has  if  its  a  baseObj */
nero_s32int y;	/*	it use  to  recond  how many times  this obj  has been input  recently只在临时区域中使用这个变量*/
nero_s32int z;
struct NerveFiber_  * inputListHead;/*其实究竟对于一个神经元来说是不是需要这个输入神经元的链表，*/
					/*好像其实不是那么必要的是吧，因为，这实际上会造成冗余数据*/
					/*那么如果该神经元是一个NeuronObject，那么inputListHead指向该*/
					/*对象的数据，如果该神经元表示一个存抽象概念，则没有数据*/
					/*如果是一个ActNero，则该神经元的功能是保存数据*/
					/*但是如果是一个NeuronObject，是指向第一个数据呢，还是*/
					/*说inputListHead指向一个数据的链表，显然指向一个数据的神经元*/
					/*然后让这个神经元(纤维)指向后续的数据*/
					
					/*特别的，对于一个基类来说，它的inputListHead为NULL*/
					/*而他的outputListHead链表，则指向所有该类下的所以神经元*/
					
struct NerveFiber_   * outputListHead; 
};





/*神经纤维---用来连接各个神经元*/
/*
msg1：
低位			高位
1-------8  9-----16 17-----24  25----32
1111 1111 1111 1111 1111 1111 1111 1111 neroConf
1-8位表示该链接的强度，就是没被搜索并匹配成功到一次，加1,暂时100最大，初始化为0,对于计算机来说，250次算是很少的了,如果实在不够用，只好放在变量time里面了
9-10位表示该神经纤维的类型：
	指向该纤维所属神经元存储数据的神经元      #define	Fiber_PointToData	00
	指向该纤维所属神经元的上层概念的神经元	#define	Fiber_PointToUpperLayer	01
	指向该纤维所属神经元的下层概念的神经元 	#define	Fiber_PointToLowerLayer	10
	指向该纤维所属神经元的同层次概念的神经元	#define	Fiber_PointToSameLayer	11
	就是说如果为Fiber_PointToUpperLayer	01，那么第9位为1，第10位为0
	
11-12位（）：
        有且必须存在一个                         #define Fiber_PointToUniqueObj	00
	可重复，但必须存在一个	                #define	Fiber_PointToMutiObj	01
	可有可没有 	                        #define	Fiber_PointToUnnecessaryObj	10
	就是说如果为Fiber_PointToMutiObj	01，那么第11位为1，第12位为0       

13-14位：用来表明该纤维结构中指针obj所指向对象得所属区域

	所指向对象所在区域为永久得NeroInPool			#define	Fiber_ObjInNeroPool	00
	所指向对象所在区域为StagingAreaNeroPool	 	#define	Fiber_ObjInSAPool	01


time：
低位			高位
1-------8  9-----16 17-----24  25----32
1111 1111 1111 1111 1111 1111 1111 1111 	
1-20位存储上次被访问的时间（包括修改，被成功匹配的情况），初始化为当前系统时间	
		该信息会被修改的时间包括：
			1:创建时候
			2:被成功匹配的时候，相应链接被修改  Process_StrengthenLink=》gainFiberStrengthen




*/

struct NerveFiber_
{
	struct ActivationNeuron   *obj;
	struct NerveFiber_ * next;
	nero_us32int msg1;/*存储额外的信息*/
	nero_us32int time;/*有关修改时间的信息*/
};




#define Nero_DeBuging16_12_30



























