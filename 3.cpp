#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<conio.h> 
using namespace std;
#define N 30    //最大顶点数 
#define MaxInt 32000  //最大值，用于表示结点间无边 
struct scenic{       //存放景点的信息，包括序号，名称，介绍 
	int number;
	char name[20];
	char introduce[100];
};
struct AMGraph {  //存放邻接矩阵的信息，包括两边的权值，顶点数和边数 
	int arcs[N][N];
	int vexnum,arcnum;
}; 
bool visited[N];   //用于标记某结点是否已访问 
int d[8];           //用于保存一条路径上的顶点 
void assignment(scenic [],int );    //各个函数的声明   
void print(scenic [], int );
void initialAMGraph(AMGraph &); 
void checkPath(AMGraph, scenic []);
void shortestPath(AMGraph, scenic []);
void checkScenic(scenic []);
void correct(AMGraph &, scenic []);
void allPath(AMGraph &, scenic []);
void pringG(AMGraph );
void main(){         //主函数 
	scenic s[N];    //存储景点信息 
	AMGraph college; //声明邻接矩阵 
	initialAMGraph(college); //初始化邻接矩阵 
	char option;      //用与switch语句选择 
	assignment(s, N); //给所有景点赋值 
	while(true) {
			cout<<"广外校园导游系统"<<"  "<<"制作人:周嘉均"<<"  "<<"班级:计算机1403班"<<"  "<<"学号:20141002356"<<endl;          //输出主菜单 
			cout<<"   "<<"_____________________________________________________________________"<<endl;
			cout<<endl;
			cout<<"   "<<"1.学校景点介绍。"<<endl; 
			cout<<endl;
			cout<<"   "<<"2.查询浏览线路。"<<endl;
			cout<<endl;
			cout<<"   "<<"3.查询景点间的最短路径。"<<endl;
			cout<<endl;
			cout<<"   "<<"4.景点信息查询。"<<endl;
			cout<<endl; 
			cout<<"   "<<"5.更改图信息。"<<endl;
			cout<<endl;
			cout<<"   "<<"6.查询景点间可行路径。"<<endl;
			cout<<endl; 
			cout<<"   "<<"7.输出图的邻接矩阵。" <<endl;
			cout<<endl;
			cout<<"   "<<"8.退出。" <<endl;
			cout<<endl;
			cout<<"   "<<"_____________________________________________________________________"<<endl;
			cin>>option;
			switch (option){        //根据输入调用各个函数 
				case '1': print(s,college.vexnum);break;
				case '2': checkPath(college, s);break; 
				case '3': shortestPath(college, s);break;
				case '4': checkScenic(s);break;
				case '5': correct(college, s);break;
				case '6': allPath(college, s);break;
				case '7': pringG(college);break;
				case '8': exit(0);break;
			}
	}	
}
void assignment(scenic s[],int n){  //给景点赋值函数 
	for(int i = 0; i < n; i++)  s[i].number = i;
	strcpy(s[0].name,"第三饭堂博雅园"); 
	strcpy(s[0].introduce,"价廉物美的饭堂，靠近内环，主要服务范围在南苑7到13栋"); 
	strcpy(s[1].name,"第二饭堂风采园"); 
	strcpy(s[1].introduce,"饭菜精致的饭堂，靠近中环，饭菜好吃但价格略贵");
	strcpy(s[2].name,"第一饭堂文采园"); 
	strcpy(s[2].introduce,"应有尽有价格合理的饭堂，菜式较多，价格也合理");
	strcpy(s[3].name,"教学楼正门"); 
	strcpy(s[3].introduce,"风景优美，略显校园之大气");
	strcpy(s[4].name,"广外长隧道"); 
	strcpy(s[4].introduce,"各社团宣传活动的前沿阵地，沟通了生活区与教学区，是广外的交通要道");
	strcpy(s[5].name,"广外高尔夫球场"); 
	strcpy(s[5].introduce,"可进行初级的高尔夫练习，学校开展高尔夫教学的场地");
	strcpy(s[6].name,"广外篮球场"); 
	strcpy(s[6].introduce,"众多篮球场免费开放供学生享用");
	strcpy(s[7].name,"广外网球场"); 
	strcpy(s[7].introduce,"球场数量充足，进入需要购票");
	strcpy(s[8].name,"广外游泳池"); 
	strcpy(s[8].introduce,"夏天降暑的好地方，进入需要购票，还需要持合格的游泳证");
	strcpy(s[9].name,"广外足球场1"); 
	strcpy(s[9].introduce,"人造草足球场，外有四百米跑道围绕，附有单杠双杠，跳远，铅球等设备场");         
    strcpy(s[10].name,"广外足球场2"); 
	strcpy(s[10].introduce,"真草足球场，外有标准观众席，四百米跑道围绕，附有单杠双杠，跳远，铅球等设备场");
	strcpy(s[11].name,"广外室内羽毛球场"); 
	strcpy(s[11].introduce,"宽敞的羽毛球场，内有空调，观众席，最近更新为塑胶地板"); 
	strcpy(s[12].name,"广外语心湖"); 
	strcpy(s[12].introduce,"清澈的湖水与高耸的教学楼交相辉映，养有国家保护动物黑天鹅");
	strcpy(s[13].name,"广外实验楼"); 
	strcpy(s[13].introduce,"实验设备齐全，学术氛围浓厚，广外人才辈出的好地方");
	strcpy(s[14].name,"广外图书馆"); 
	strcpy(s[14].introduce,"存书量充足，内设有自习室和电子阅览室，是广外学子充实自我的好地方");
	strcpy(s[15].name,"广外大会堂"); 
	strcpy(s[15].introduce,"广外南校最大的舞台会议室，内有空调，充足的观众席，举办大型晚会与讲座");
	strcpy(s[16].name,"广外B8学习报告厅"); 
	strcpy(s[16].introduce,"比大会堂稍小的舞台会议室，内有空调，充足观众席");
	strcpy(s[17].name,"广外图书馆报告厅"); 
	strcpy(s[17].introduce,"在图书馆旁边的舞台会议室，充足观众席，举办学术研讨会等");
	strcpy(s[18].name,"广外艺术楼"); 
	strcpy(s[18].introduce,"广外艺术生常驻学习，内有钢琴室，美术展览等，阳春白雪，风格高雅");
	strcpy(s[19].name,"广外院系楼"); 
	strcpy(s[19].introduce,"广外南校各学院老师办公的地方，建筑风格高大上");
	strcpy(s[20].name,"广外八角楼"); 
	strcpy(s[20].introduce,"广外教师管理层中的高层人员工作地方，建筑漂亮，具有特色");
	strcpy(s[21].name,"广外教职工食堂"); 
	strcpy(s[21].introduce,"被称为广外四饭的神秘地方，地处偏僻，供老师享用，很少学生入内");
	strcpy(s[22].name,"广外办公楼"); 
	strcpy(s[22].introduce,"广外校级领导、教师的办公地方，建筑风格优雅高端");
	strcpy(s[23].name,"广外院系楼222室"); 
	strcpy(s[23].introduce,"广外思科信息学院团委学生会的办公室");
	strcpy(s[24].name,"广外云山忆站"); 
	strcpy(s[24].introduce,"广外著名休闲专区，由学生经营，开小会议的优先选择");
	strcpy(s[25].name,"广外门诊部"); 
	strcpy(s[25].introduce,"方便学生看病，价格合理，每年举行体检");
	strcpy(s[26].name,"广外正门"); 
	strcpy(s[26].introduce,"广外的正门，牌匾大气，面向外环，交通方便");
	strcpy(s[27].name,"广外孙中山雕像"); 
	strcpy(s[27].introduce,"著名革命家孙中山的雕像");
	strcpy(s[28].name,"广外又康超市"); 
	strcpy(s[28].introduce,"广外第一大超市，商品供应齐全，价格稍贵");
	strcpy(s[29].name,"广外云山书吧"); 
	strcpy(s[29].introduce,"广外著名咖啡馆，由学生经营，休闲聊天的好去处");
} 
void print(scenic s[], int n){ //输出所有景点信息函数 
	cout<<left<<setw(5)<<"序号"<<left<<setw(20)<<"名称"<<left<<setw(20)<<"介绍"<<endl;
	for(int i = 0; i < n; i++){
		cout<<left<<setw(5)<<s[i].number<<left<<setw(20)<<s[i].name<<left<<setw(20)<<s[i].introduce<<endl ;
	}
}
void initialAMGraph(AMGraph &c) {//邻接矩阵初始化函数
   	c.vexnum = 30;
	c.arcnum = 44;
	for(int i=0; i < c.vexnum; i++)
		for(int j = 0; j<c.vexnum; j++ )
			c.arcs[i][j] = MaxInt;    //先将全部景点间的边赋值为无穷大 
	c.arcs[0][1] = 100; c.arcs[0][28]= 50;  c.arcs[2][28]= 50;  c.arcs[1][4] = 30;
	c.arcs[1][2] = 20;  c.arcs[2][25] = 15; c.arcs[5][25] = 50; c.arcs[5][24] = 45;
	c.arcs[4][24] = 17; c.arcs[3][4] = 18;  c.arcs[3][24] = 14; c.arcs[24][27]= 13;
	c.arcs[5][27] = 22; c.arcs[5][14] = 19; c.arcs[14][27] = 9; c.arcs[5][6] = 7;
	c.arcs[6][9] = 5;   c.arcs[6][8] = 5;   c.arcs[8][9] = 5;   c.arcs[7][8] = 5; 
	c.arcs[7][9] = 5;   c.arcs[7][10] = 15; c.arcs[10][11] = 6; c.arcs[14][15] = 25; 
	c.arcs[15][17] = 20; c.arcs[17][29] = 3; c.arcs[18][29] = 6; c.arcs[18][26] = 7; 
	c.arcs[13][26] = 8; c.arcs[12][13] = 4; c.arcs[12][16] = 15; c.arcs[13][19] = 12; 
	c.arcs[12][19] = 10;c.arcs[19][20] = 4; c.arcs[20][21] = 6; c.arcs[21][22] = 3; 
	c.arcs[20][23] = 4; c.arcs[21][23] = 2; c.arcs[22][23] = 3; c.arcs[15][29] = 17;
	c.arcs[15][18] = 15; c.arcs[15][26] = 16; c.arcs[15][16] = 14; c.arcs[13][16] = 10;
	for(i = 0; i < c.vexnum; i++) 
		for(int j = 0; j < c.vexnum; j++)
			if(c.arcs[i][j] < MaxInt) {  //将邻接矩阵对称部分赋值，如，若顶点1，2之间权值为3，则将2，1也赋值为3 
				c.arcs[j][i] = c.arcs[i][j];
			}
}
void checkPath(AMGraph g, scenic s[]) {  //查询输入结点到各个结点的最短路径
	int k,k1,d[g.vexnum],path[g.vexnum],path1[g.vexnum],sum ; //分别用于接收输入的值，保存输入的值用于迭代，保存最短路径的长度，反向保存最短路径的顶点，正向保存最短路径，路径总长 
	bool S[N]; //记录景点是否已访问 
	cout<<"请输入起点景点的序号"<<endl;
	cin>>k; 
	k1 = k;
	for(int i = 0; i < g.vexnum; i++){  //Dijkstra算法 
		S[i] = false;
		d[i] = g.arcs[k][i];
		if(d[i] < MaxInt) path[i] = k;
		else path[i] = -1; 
	}
	S[k] = true;
	d[k] =  0;
	for(i = 1; i < g.vexnum; i++){
		int min = MaxInt;
		for(int w = 0; w < g.vexnum; w++){
			if(!S[w] && d[w] < min) {
				k = w;
				min = d[w];
			}
		S[k] = true;
		for(int w = 0; w < g.vexnum; w++){
			if(!S[w] && (d[k] + g.arcs[k][w]) < d[w]) {
				d[w] = d[k] + g.arcs[k][w];
				path[w] = k;
			}
		}	
		}
	}
	for(i = 0; i < g.vexnum; i++){  //借助path1输入正向路径，以及路径长度 
		sum = 0;
		if(i==k1) continue;  //跳过从起点到起点的路径 
		cout<<s[k1].name<<" 到 "<<s[i].name<<" 的最短路线为："<<s[k1].name<<"->";
		int j = 0;  
		int a = path[i];
		sum += g.arcs[a][i];
		while(a != k1) {    //用path1保存path的值，直到到达终点，同时计算长度 
			sum += g.arcs[a][path[a]]; 
			path1[j++] = a;
			a = path[a];
		}
		for(int x = j-1; x >= 0; x--) { 
			cout<<s[path1[x]].name<<"->";
		}
		
		cout<<s[i].name<<" 总长度为："<<sum<<"米"<<endl<<endl;
	}
}
void shortestPath(AMGraph g, scenic s[]) {  //查找两个景点间的最短路径
	int a, b, d[g.vexnum][g.vexnum], path[g.vexnum][g.vexnum], path1[g.vexnum];//分别用于接收两个景点的值，保存两个景点间的最短长度，保存反向路径轨迹，保存正向轨迹 
	cout<<"输入要查询的两个景点的序号"<<endl;
	cin>>a>>b;
	for(int i = 0; i < g.vexnum; i++)   //Floyd算法 
		for(int j = 0; j < g.vexnum; j++) {
			d[i][j] = g.arcs[i][j];
			if(d[i][j] < MaxInt) path[i][j] = i;
			else path[i][j] = -1;
		}
	for(int k = 0; k < g.vexnum; k++)
		for(int i = 0; i < g.vexnum; i++)
			for(int j = 0; j < g.vexnum; j++) {
				if((d[i][k] + d[k][j]) < d[i][j]) {
					path[i][j] = path[k][j];
					d[i][j] = d[i][k] + d[k][j];
				}
			}
	int c = path[a][b];
	path1[0] = c;
	int sum = g.arcs[c][b];
	int j = 1;
	while((c = path[a][c]) != a) {  //用path1接收path的路径 
		path1[j++] = c;
	}
	cout<<s[a].name<<" 到 "<<s[b].name<<" 的最短路线为："<<s[a].name<<"->";
	for(i = j-1; i >= 0; i--) {        //输出路径并计算长度 
		if(i != 0) sum += g.arcs[path1[i]][path1[i-1]];
		cout<<s[path1[i]].name<<"->";
	} 
	sum += g.arcs[path1[0]][b];
	cout<<s[b].name<<" 总长度为: "<<sum<<"米"<<endl<<endl; 
}
void checkScenic(scenic s[]) {   //查询景点信息函数
	int a;
	cout<<"输入要查询的景点的序号"<<endl;
	cin>>a;
	cout<<"序号："<<s[a].number<<endl
	 	<<"名称："<<s[a].name<<endl
		<<"介绍："<<s[a].introduce<<endl<<endl;
}
void rebuild(AMGraph &g, scenic s[]) {  //重新构图函数
	cout<<"请输入新图的点数和边数"<<endl;
	cin>>g.vexnum>>g.arcnum;
	for(int i = 0; i < g.vexnum; i++)
		s[i].number = i;
	cout<<"请输入各个顶点的名称"<<endl;
	cin.get();   //吃掉回车键，使下面的cin.getline可以顺利进行 
	for(i = 0; i < g.vexnum; i++)
	{
	    cin.getline(s[i].name, 20);}
	cout<<"请输入各个顶点的介绍"<<endl;
	for(i = 0; i < g.vexnum; i++)
		cin.getline(s[i].introduce, 100);
	for(i = 0; i < g.vexnum ; i++)   //先将邻接矩阵初始化 
		for (int j = 0; j < g.vexnum; j++)
		  	g.arcs[i][j] = MaxInt;
	cout<<"请输入每条边的两个顶点和边的权值"<<endl;
	int a,b;
	for(i = 0; i < g.arcnum; i++){
		cin>>a>>b;
		cin>>g.arcs[a][b];
		g.arcs[b][a] = g.arcs[a][b];
	} 
	cout<<"构图成功"<<endl;
}
void deleteVex(AMGraph &g, scenic s[]) { //删除结点函数
	if(g.vexnum <= 0) {
		cout<<"已无结点"<<endl;
		return; 
	}
	cout<<"请输入要删除结点的序号"<<endl;
	int a;
	cin>>a;
	s[g.vexnum-1].number = s[a].number;   //将最后一个结点的信息移到被删除的位置 
	strcpy(s[a].name, s[g.vexnum-1].name);
	strcpy(s[a].introduce, s[g.vexnum-1].introduce);
	for(int i = 0; i < g.vexnum; i++) { //切断该景点与其它景点的边 
		if(g.arcs[i][a] < MaxInt) {
			g.arcs[i][a] = MaxInt;
			g.arcnum--;
		} 
		if(g.arcs[a][i] < MaxInt) {
			g.arcs[a][i] = MaxInt;
			g.arcnum--;
		}
	}
	g.vexnum--;
	cout<<"修改成功"<<endl;
}
void deleteArc(AMGraph &g, scenic s[]) { //删除边函数
	if(g.arcnum <= 0) {
		cout<<"已没有边"<<endl;
		return;
	} 
	int a,b;
	cout<<"请输入要删除的边的两个顶点"<<endl;
	cin>>a>>b;
	g.arcs[a][b] = g.arcs[b][a] = MaxInt; 
	cout<<"修改成功"<<endl;
} 
void addVex(AMGraph &g, scenic s[]) { //增加结点函数
	if(g.vexnum >= N-1) {
		cout<<"结点数已满"<<endl;
		return; 
	}
	s[g.vexnum+1].number = g.vexnum;
	cout<<"请输入要增加结点的名称"<<endl;
	cin.getline(s[g.vexnum+1].name, 20);
	cout<<"请输入要增加结点的介绍"<<endl;
	cin.getline(s[g.vexnum+1].introduce, 100); 
	cout<<"请输入与该新增结点相连的结点序号以及边的权值,以-1结束"<<endl;
	int a;
	cin>>a;
	while(a != -1) {   //将新增结点以及相关的边补充进邻接矩阵 
		cin>>g.arcs[a][g.vexnum];
		g.arcs[g.vexnum][a] = g.arcs[a][g.vexnum];
		g.arcnum++;
		cin>>a;
	} 
	g.vexnum++;
	cout<<"修改成功"<<endl;
}
void addArc(AMGraph &g) {   //增加边函数
	cout<<"请输入要插入的边的两个顶点以及权值"<<endl;
	int a, b, c;
	cin>>a>>b>>c;
	g.arcs[a][b] = g.arcs[a][b] = c; 
	cout<<"修改成功"<<endl;
}
void refresh(scenic s[]) {   //更新景点信息函数
	cout<<"输入你要修改信息的景点的序号"<<endl;
	int a; //保存要修改的景点的序号 
	char b = '0'; //switch选项变量 
	cin>>a;
	while(b != '3') {   
		cout<<"1.修改名称"<<endl  //输出菜单 
			<<"2.修改介绍"<<endl
			<<"3.退出"<<endl; 
		cin>>b;
		switch(b) {
			case '1':{
				cout<<"输入新名称"<<endl;
				cin.get();   //吃掉回车键，使下面的cin.getline可以顺利进行 
				cin.getline(s[a].name, 20);
				cout<<"修改成功"<<endl;
				break;
			}
			case '2':{
				cout<<"输入新介绍"<<endl;
				cin.get();  //吃掉回车键，使下面的cin.getline可以顺利进行 
				cin.getline(s[a].introduce, 100); 
				cout<<"修改成功"<<endl;
				break;
			}
			case '3':break;
		}
	} 
}
void correct(AMGraph &g, scenic s[]) {  //重新构图函数
	cout<<"1.再次建图。"<<endl
		<<endl
		<<"2.删除结点。"<<endl
		<<endl
		<<"3.删除边。"<<endl
		<<endl
		<<"4.增加结点。"<<endl
		<<endl
		<<"5.增加边。"<<endl
		<<endl
		<<"6.更新信息。"<<endl
		<<endl
		<<"7.返回。"<<endl;
	char option;   //switch函数选项 
	cin>>option;
	switch(option) {
		case '1': rebuild(g, s);break;  //调用各个修改函数 
		case '2': deleteVex(g, s);break;
		case '3': deleteArc(g, s);break;
		case '4': addVex(g, s);break; 
		case '5': addArc(g);break;
		case '6': refresh(s);break;
		case '7':break;
	}
}
void path(int a, int b, int k, AMGraph g, scenic s[]) {  //递归求两景点间的长度少于8的路径
	if(d[k] == b && k < 8) {           //若当前保存路径的最后一个就是终点，则输出路径 
		for(int i = 0; i < k; i++)
			cout<<s[d[i]].name<<"->";
		cout<<s[d[k]].name<<endl<<endl;
	}
	else {
		int t = 0;  //从零开始试探各个顶点 
		while(t < g.vexnum) {
			if(g.arcs[d[k]][t] < MaxInt && !visited[t]) { //两点间有路且该顶点未被访问，则访问该顶点后继续递归 
				visited[t] = true;
				d[k+1] = t;
				path(a, b, k+1, g, s);
				visited[t] = false;    //将顶点重新置为未访问，后面继续访问 
			}
			t++;
		} //while 
	}
}
void allPath(AMGraph &g, scenic s[]) {  //查询景点间所有路径长度少于8的路径
	cout<<"输入要查询景点的序号"<<endl;
	int a, b, k = 0;   //分别用于接收输入的两个景点序号， 递归初始量 
	cin>>a>>b;
	visited[a] = true;  //先访问起点 
	d[0] = a;
	path(a,b,k, g, s);
}
void pringG(AMGraph g) {  //打印邻接矩阵
	cout<<"0表示两点间无边"<<endl;
	for(int i = 0; i < g.vexnum; i++) {
		for(int j = 0; j < g.vexnum; j++) {
			if(g.arcs[i][j] < MaxInt) cout<<g.arcs[i][j]<<"\t";
			else cout<<"0"<<"\t";   //以0表示无边 
		}
		cout<<endl;
	}
	cout<<endl;
}