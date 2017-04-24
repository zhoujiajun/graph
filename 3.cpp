#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<conio.h> 
using namespace std;
#define N 30    //��󶥵��� 
#define MaxInt 32000  //���ֵ�����ڱ�ʾ�����ޱ� 
struct scenic{       //��ž������Ϣ��������ţ����ƣ����� 
	int number;
	char name[20];
	char introduce[100];
};
struct AMGraph {  //����ڽӾ������Ϣ���������ߵ�Ȩֵ���������ͱ��� 
	int arcs[N][N];
	int vexnum,arcnum;
}; 
bool visited[N];   //���ڱ��ĳ����Ƿ��ѷ��� 
int d[8];           //���ڱ���һ��·���ϵĶ��� 
void assignment(scenic [],int );    //��������������   
void print(scenic [], int );
void initialAMGraph(AMGraph &); 
void checkPath(AMGraph, scenic []);
void shortestPath(AMGraph, scenic []);
void checkScenic(scenic []);
void correct(AMGraph &, scenic []);
void allPath(AMGraph &, scenic []);
void pringG(AMGraph );
void main(){         //������ 
	scenic s[N];    //�洢������Ϣ 
	AMGraph college; //�����ڽӾ��� 
	initialAMGraph(college); //��ʼ���ڽӾ��� 
	char option;      //����switch���ѡ�� 
	assignment(s, N); //�����о��㸳ֵ 
	while(true) {
			cout<<"����У԰����ϵͳ"<<"  "<<"������:�ܼξ�"<<"  "<<"�༶:�����1403��"<<"  "<<"ѧ��:20141002356"<<endl;          //������˵� 
			cout<<"   "<<"_____________________________________________________________________"<<endl;
			cout<<endl;
			cout<<"   "<<"1.ѧУ������ܡ�"<<endl; 
			cout<<endl;
			cout<<"   "<<"2.��ѯ�����·��"<<endl;
			cout<<endl;
			cout<<"   "<<"3.��ѯ���������·����"<<endl;
			cout<<endl;
			cout<<"   "<<"4.������Ϣ��ѯ��"<<endl;
			cout<<endl; 
			cout<<"   "<<"5.����ͼ��Ϣ��"<<endl;
			cout<<endl;
			cout<<"   "<<"6.��ѯ��������·����"<<endl;
			cout<<endl; 
			cout<<"   "<<"7.���ͼ���ڽӾ���" <<endl;
			cout<<endl;
			cout<<"   "<<"8.�˳���" <<endl;
			cout<<endl;
			cout<<"   "<<"_____________________________________________________________________"<<endl;
			cin>>option;
			switch (option){        //����������ø������� 
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
void assignment(scenic s[],int n){  //�����㸳ֵ���� 
	for(int i = 0; i < n; i++)  s[i].number = i;
	strcpy(s[0].name,"�������ò���԰"); 
	strcpy(s[0].introduce,"���������ķ��ã������ڻ�����Ҫ����Χ����Է7��13��"); 
	strcpy(s[1].name,"�ڶ����÷��԰"); 
	strcpy(s[1].introduce,"���˾��µķ��ã������л������˺óԵ��۸��Թ�");
	strcpy(s[2].name,"��һ�����Ĳ�԰"); 
	strcpy(s[2].introduce,"Ӧ�о��м۸����ķ��ã���ʽ�϶࣬�۸�Ҳ����");
	strcpy(s[3].name,"��ѧ¥����"); 
	strcpy(s[3].introduce,"�羰����������У԰֮����");
	strcpy(s[4].name,"���ⳤ���"); 
	strcpy(s[4].introduce,"�������������ǰ����أ���ͨ�����������ѧ�����ǹ���Ľ�ͨҪ��");
	strcpy(s[5].name,"����߶�����"); 
	strcpy(s[5].introduce,"�ɽ��г����ĸ߶�����ϰ��ѧУ��չ�߶����ѧ�ĳ���");
	strcpy(s[6].name,"��������"); 
	strcpy(s[6].introduce,"�ڶ�������ѿ��Ź�ѧ������");
	strcpy(s[7].name,"��������"); 
	strcpy(s[7].introduce,"���������㣬������Ҫ��Ʊ");
	strcpy(s[8].name,"������Ӿ��"); 
	strcpy(s[8].introduce,"���콵��ĺõط���������Ҫ��Ʊ������Ҫ�ֺϸ����Ӿ֤");
	strcpy(s[9].name,"��������1"); 
	strcpy(s[9].introduce,"��������򳡣������İ����ܵ�Χ�ƣ����е���˫�ܣ���Զ��Ǧ����豸��");         
    strcpy(s[10].name,"��������2"); 
	strcpy(s[10].introduce,"������򳡣����б�׼����ϯ���İ����ܵ�Χ�ƣ����е���˫�ܣ���Զ��Ǧ����豸��");
	strcpy(s[11].name,"����������ë��"); 
	strcpy(s[11].introduce,"������ë�򳡣����пյ�������ϯ���������Ϊ�ܽ��ذ�"); 
	strcpy(s[12].name,"�������ĺ�"); 
	strcpy(s[12].introduce,"�峺�ĺ�ˮ����ʵĽ�ѧ¥�����ӳ�����й��ұ�����������");
	strcpy(s[13].name,"����ʵ��¥"); 
	strcpy(s[13].introduce,"ʵ���豸��ȫ��ѧ����ΧŨ�񣬹����˲ű����ĺõط�");
	strcpy(s[14].name,"����ͼ���"); 
	strcpy(s[14].introduce,"���������㣬��������ϰ�Һ͵��������ң��ǹ���ѧ�ӳ�ʵ���ҵĺõط�");
	strcpy(s[15].name,"��������"); 
	strcpy(s[15].introduce,"������У������̨�����ң����пյ�������Ĺ���ϯ���ٰ��������뽲��");
	strcpy(s[16].name,"����B8ѧϰ������"); 
	strcpy(s[16].introduce,"�ȴ������С����̨�����ң����пյ����������ϯ");
	strcpy(s[17].name,"����ͼ��ݱ�����"); 
	strcpy(s[17].introduce,"��ͼ����Աߵ���̨�����ң��������ϯ���ٰ�ѧ�����ֻ��");
	strcpy(s[18].name,"��������¥"); 
	strcpy(s[18].introduce,"������������פѧϰ�����и����ң�����չ���ȣ�������ѩ��������");
	strcpy(s[19].name,"����Ժϵ¥"); 
	strcpy(s[19].introduce,"������У��ѧԺ��ʦ�칫�ĵط����������ߴ���");
	strcpy(s[20].name,"����˽�¥"); 
	strcpy(s[20].introduce,"�����ʦ������еĸ߲���Ա�����ط�������Ư����������ɫ");
	strcpy(s[21].name,"�����ְ��ʳ��"); 
	strcpy(s[21].introduce,"����Ϊ�����ķ������صط����ش�ƫƧ������ʦ���ã�����ѧ������");
	strcpy(s[22].name,"����칫¥"); 
	strcpy(s[22].introduce,"����У���쵼����ʦ�İ칫�ط�������������Ÿ߶�");
	strcpy(s[23].name,"����Ժϵ¥222��"); 
	strcpy(s[23].introduce,"����˼����ϢѧԺ��ίѧ����İ칫��");
	strcpy(s[24].name,"������ɽ��վ"); 
	strcpy(s[24].introduce,"������������ר������ѧ����Ӫ����С���������ѡ��");
	strcpy(s[25].name,"�������ﲿ"); 
	strcpy(s[25].introduce,"����ѧ���������۸����ÿ��������");
	strcpy(s[26].name,"��������"); 
	strcpy(s[26].introduce,"��������ţ����Ҵ����������⻷����ͨ����");
	strcpy(s[27].name,"��������ɽ����"); 
	strcpy(s[27].introduce,"��������������ɽ�ĵ���");
	strcpy(s[28].name,"�����ֿ�����"); 
	strcpy(s[28].introduce,"�����һ���У���Ʒ��Ӧ��ȫ���۸��Թ�");
	strcpy(s[29].name,"������ɽ���"); 
	strcpy(s[29].introduce,"�����������ȹݣ���ѧ����Ӫ����������ĺ�ȥ��");
} 
void print(scenic s[], int n){ //������о�����Ϣ���� 
	cout<<left<<setw(5)<<"���"<<left<<setw(20)<<"����"<<left<<setw(20)<<"����"<<endl;
	for(int i = 0; i < n; i++){
		cout<<left<<setw(5)<<s[i].number<<left<<setw(20)<<s[i].name<<left<<setw(20)<<s[i].introduce<<endl ;
	}
}
void initialAMGraph(AMGraph &c) {//�ڽӾ����ʼ������
   	c.vexnum = 30;
	c.arcnum = 44;
	for(int i=0; i < c.vexnum; i++)
		for(int j = 0; j<c.vexnum; j++ )
			c.arcs[i][j] = MaxInt;    //�Ƚ�ȫ�������ı߸�ֵΪ����� 
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
			if(c.arcs[i][j] < MaxInt) {  //���ڽӾ���ԳƲ��ָ�ֵ���磬������1��2֮��ȨֵΪ3����2��1Ҳ��ֵΪ3 
				c.arcs[j][i] = c.arcs[i][j];
			}
}
void checkPath(AMGraph g, scenic s[]) {  //��ѯ�����㵽�����������·��
	int k,k1,d[g.vexnum],path[g.vexnum],path1[g.vexnum],sum ; //�ֱ����ڽ��������ֵ�����������ֵ���ڵ������������·���ĳ��ȣ����򱣴����·���Ķ��㣬���򱣴����·����·���ܳ� 
	bool S[N]; //��¼�����Ƿ��ѷ��� 
	cout<<"��������㾰������"<<endl;
	cin>>k; 
	k1 = k;
	for(int i = 0; i < g.vexnum; i++){  //Dijkstra�㷨 
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
	for(i = 0; i < g.vexnum; i++){  //����path1��������·�����Լ�·������ 
		sum = 0;
		if(i==k1) continue;  //��������㵽����·�� 
		cout<<s[k1].name<<" �� "<<s[i].name<<" �����·��Ϊ��"<<s[k1].name<<"->";
		int j = 0;  
		int a = path[i];
		sum += g.arcs[a][i];
		while(a != k1) {    //��path1����path��ֵ��ֱ�������յ㣬ͬʱ���㳤�� 
			sum += g.arcs[a][path[a]]; 
			path1[j++] = a;
			a = path[a];
		}
		for(int x = j-1; x >= 0; x--) { 
			cout<<s[path1[x]].name<<"->";
		}
		
		cout<<s[i].name<<" �ܳ���Ϊ��"<<sum<<"��"<<endl<<endl;
	}
}
void shortestPath(AMGraph g, scenic s[]) {  //�����������������·��
	int a, b, d[g.vexnum][g.vexnum], path[g.vexnum][g.vexnum], path1[g.vexnum];//�ֱ����ڽ������������ֵ������������������̳��ȣ����淴��·���켣����������켣 
	cout<<"����Ҫ��ѯ��������������"<<endl;
	cin>>a>>b;
	for(int i = 0; i < g.vexnum; i++)   //Floyd�㷨 
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
	while((c = path[a][c]) != a) {  //��path1����path��·�� 
		path1[j++] = c;
	}
	cout<<s[a].name<<" �� "<<s[b].name<<" �����·��Ϊ��"<<s[a].name<<"->";
	for(i = j-1; i >= 0; i--) {        //���·�������㳤�� 
		if(i != 0) sum += g.arcs[path1[i]][path1[i-1]];
		cout<<s[path1[i]].name<<"->";
	} 
	sum += g.arcs[path1[0]][b];
	cout<<s[b].name<<" �ܳ���Ϊ: "<<sum<<"��"<<endl<<endl; 
}
void checkScenic(scenic s[]) {   //��ѯ������Ϣ����
	int a;
	cout<<"����Ҫ��ѯ�ľ�������"<<endl;
	cin>>a;
	cout<<"��ţ�"<<s[a].number<<endl
	 	<<"���ƣ�"<<s[a].name<<endl
		<<"���ܣ�"<<s[a].introduce<<endl<<endl;
}
void rebuild(AMGraph &g, scenic s[]) {  //���¹�ͼ����
	cout<<"��������ͼ�ĵ����ͱ���"<<endl;
	cin>>g.vexnum>>g.arcnum;
	for(int i = 0; i < g.vexnum; i++)
		s[i].number = i;
	cout<<"������������������"<<endl;
	cin.get();   //�Ե��س�����ʹ�����cin.getline����˳������ 
	for(i = 0; i < g.vexnum; i++)
	{
	    cin.getline(s[i].name, 20);}
	cout<<"�������������Ľ���"<<endl;
	for(i = 0; i < g.vexnum; i++)
		cin.getline(s[i].introduce, 100);
	for(i = 0; i < g.vexnum ; i++)   //�Ƚ��ڽӾ����ʼ�� 
		for (int j = 0; j < g.vexnum; j++)
		  	g.arcs[i][j] = MaxInt;
	cout<<"������ÿ���ߵ���������ͱߵ�Ȩֵ"<<endl;
	int a,b;
	for(i = 0; i < g.arcnum; i++){
		cin>>a>>b;
		cin>>g.arcs[a][b];
		g.arcs[b][a] = g.arcs[a][b];
	} 
	cout<<"��ͼ�ɹ�"<<endl;
}
void deleteVex(AMGraph &g, scenic s[]) { //ɾ����㺯��
	if(g.vexnum <= 0) {
		cout<<"���޽��"<<endl;
		return; 
	}
	cout<<"������Ҫɾ���������"<<endl;
	int a;
	cin>>a;
	s[g.vexnum-1].number = s[a].number;   //�����һ��������Ϣ�Ƶ���ɾ����λ�� 
	strcpy(s[a].name, s[g.vexnum-1].name);
	strcpy(s[a].introduce, s[g.vexnum-1].introduce);
	for(int i = 0; i < g.vexnum; i++) { //�жϸþ�������������ı� 
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
	cout<<"�޸ĳɹ�"<<endl;
}
void deleteArc(AMGraph &g, scenic s[]) { //ɾ���ߺ���
	if(g.arcnum <= 0) {
		cout<<"��û�б�"<<endl;
		return;
	} 
	int a,b;
	cout<<"������Ҫɾ���ıߵ���������"<<endl;
	cin>>a>>b;
	g.arcs[a][b] = g.arcs[b][a] = MaxInt; 
	cout<<"�޸ĳɹ�"<<endl;
} 
void addVex(AMGraph &g, scenic s[]) { //���ӽ�㺯��
	if(g.vexnum >= N-1) {
		cout<<"���������"<<endl;
		return; 
	}
	s[g.vexnum+1].number = g.vexnum;
	cout<<"������Ҫ���ӽ�������"<<endl;
	cin.getline(s[g.vexnum+1].name, 20);
	cout<<"������Ҫ���ӽ��Ľ���"<<endl;
	cin.getline(s[g.vexnum+1].introduce, 100); 
	cout<<"���������������������Ľ������Լ��ߵ�Ȩֵ,��-1����"<<endl;
	int a;
	cin>>a;
	while(a != -1) {   //����������Լ���صı߲�����ڽӾ��� 
		cin>>g.arcs[a][g.vexnum];
		g.arcs[g.vexnum][a] = g.arcs[a][g.vexnum];
		g.arcnum++;
		cin>>a;
	} 
	g.vexnum++;
	cout<<"�޸ĳɹ�"<<endl;
}
void addArc(AMGraph &g) {   //���ӱߺ���
	cout<<"������Ҫ����ıߵ����������Լ�Ȩֵ"<<endl;
	int a, b, c;
	cin>>a>>b>>c;
	g.arcs[a][b] = g.arcs[a][b] = c; 
	cout<<"�޸ĳɹ�"<<endl;
}
void refresh(scenic s[]) {   //���¾�����Ϣ����
	cout<<"������Ҫ�޸���Ϣ�ľ�������"<<endl;
	int a; //����Ҫ�޸ĵľ������� 
	char b = '0'; //switchѡ����� 
	cin>>a;
	while(b != '3') {   
		cout<<"1.�޸�����"<<endl  //����˵� 
			<<"2.�޸Ľ���"<<endl
			<<"3.�˳�"<<endl; 
		cin>>b;
		switch(b) {
			case '1':{
				cout<<"����������"<<endl;
				cin.get();   //�Ե��س�����ʹ�����cin.getline����˳������ 
				cin.getline(s[a].name, 20);
				cout<<"�޸ĳɹ�"<<endl;
				break;
			}
			case '2':{
				cout<<"�����½���"<<endl;
				cin.get();  //�Ե��س�����ʹ�����cin.getline����˳������ 
				cin.getline(s[a].introduce, 100); 
				cout<<"�޸ĳɹ�"<<endl;
				break;
			}
			case '3':break;
		}
	} 
}
void correct(AMGraph &g, scenic s[]) {  //���¹�ͼ����
	cout<<"1.�ٴν�ͼ��"<<endl
		<<endl
		<<"2.ɾ����㡣"<<endl
		<<endl
		<<"3.ɾ���ߡ�"<<endl
		<<endl
		<<"4.���ӽ�㡣"<<endl
		<<endl
		<<"5.���ӱߡ�"<<endl
		<<endl
		<<"6.������Ϣ��"<<endl
		<<endl
		<<"7.���ء�"<<endl;
	char option;   //switch����ѡ�� 
	cin>>option;
	switch(option) {
		case '1': rebuild(g, s);break;  //���ø����޸ĺ��� 
		case '2': deleteVex(g, s);break;
		case '3': deleteArc(g, s);break;
		case '4': addVex(g, s);break; 
		case '5': addArc(g);break;
		case '6': refresh(s);break;
		case '7':break;
	}
}
void path(int a, int b, int k, AMGraph g, scenic s[]) {  //�ݹ����������ĳ�������8��·��
	if(d[k] == b && k < 8) {           //����ǰ����·�������һ�������յ㣬�����·�� 
		for(int i = 0; i < k; i++)
			cout<<s[d[i]].name<<"->";
		cout<<s[d[k]].name<<endl<<endl;
	}
	else {
		int t = 0;  //���㿪ʼ��̽�������� 
		while(t < g.vexnum) {
			if(g.arcs[d[k]][t] < MaxInt && !visited[t]) { //�������·�Ҹö���δ�����ʣ�����ʸö��������ݹ� 
				visited[t] = true;
				d[k+1] = t;
				path(a, b, k+1, g, s);
				visited[t] = false;    //������������Ϊδ���ʣ������������ 
			}
			t++;
		} //while 
	}
}
void allPath(AMGraph &g, scenic s[]) {  //��ѯ���������·����������8��·��
	cout<<"����Ҫ��ѯ��������"<<endl;
	int a, b, k = 0;   //�ֱ����ڽ������������������ţ� �ݹ��ʼ�� 
	cin>>a>>b;
	visited[a] = true;  //�ȷ������ 
	d[0] = a;
	path(a,b,k, g, s);
}
void pringG(AMGraph g) {  //��ӡ�ڽӾ���
	cout<<"0��ʾ������ޱ�"<<endl;
	for(int i = 0; i < g.vexnum; i++) {
		for(int j = 0; j < g.vexnum; j++) {
			if(g.arcs[i][j] < MaxInt) cout<<g.arcs[i][j]<<"\t";
			else cout<<"0"<<"\t";   //��0��ʾ�ޱ� 
		}
		cout<<endl;
	}
	cout<<endl;
}