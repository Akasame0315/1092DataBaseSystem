// This program is used in Data Base Class 3/22
// Originally for Practice of Pr4 on 2021/3/8
// possible problem for db02.c
/*
列出老師的名字和其辦公室。
列出各科目的詢問辦公室。
列出各個學生可能要去詢問問題的辦公室。
列出各個老師所教導的學生數量。
列出各個老師所教導的學生名單。
*/

#include <stdio.h>
#include <string.h>

/* ...................... the Stack data structure .................... */
template < class T >
class Bag
{
public:
	Bag (int bagCapacity = 10);
	~Bag ( );
	
	int Size( ) const;
	bool IsEmpty ( ) const;
	T& Element ( ) const;
	
	void Push (const T&);
	void Pop ();
	void Pop (T * );
	T Top();
	
private:
	T *array;
	int capacity;   // 最大容量 
	int top;
};


template < class T >
Bag < T >::Bag (int bagCapacity) : capacity (bagCapacity) {
	if (capacity < 1) throw "Capacity must be > 0";
	array = new T [capacity];
	top = -1;
}

template < class T >
Bag <T>::~Bag ( ) {delete [ ] array;}

template < class T >
void Bag <T>::Push (const T& x) {
	if (capacity == top + 1)
	{
		//ChangeSize1D (array, capacity, 2 * capacity);
		capacity *= 2;
	}
	array [++top] = x;
}

template <class T>
bool Bag<T> :: IsEmpty() const {
	if(top == -1) return(true);
	else return(false); 
}

template <class T>
T Bag<T> :: Top() {
	return array[top];
}

template < class T >
void Bag < T >::Pop ( T *x) {
	if (IsEmpty ( )) throw "Bag is empty, cannot delete";
	int deletePos = top / 2;
	//copy (array + deletePos + 1, ayyay + top + 1, array + deletePos);
			// 使陣列緊湊
	*x = array[top];
	array [ top-- ].~T ( ) ; // T的解構子
}

template < class T >
void Bag < T >::Pop () {
	if (IsEmpty ( )) throw "Bag is empty, cannot delete";
	int deletePos = top / 2;
	//copy (array + deletePos + 1, ayyay + top + 1, array + deletePos);
			// 使陣列緊湊
	array [ top-- ].~T ( ) ; // T的解構子
}

// ...............
template <class T>
class Stack:public Bag<T> {
public:
	Stack(int cap);

};

template <class T>
Stack<T>::Stack(int cap) {
	Bag<T>();
}

/* ...................................... */

struct student {
	int sid;
	char name[100], phone[20], birthday[20];
	int class1, class2, class3; // 修課，寫入課程標號 
};

struct course {
	int ID;
	char name[100];
	int credit;
};

// new struct in db02
struct teacher {
	int tid;
	char name[100];
	int office;
	int teaching;
};
struct teacher TabTeacher[] = {
	{22, "Chen", 715, 2}, \
	{22, "Chen", 715, 3}, \
	{23, "Yang", 723, 1}, \
	{99, "May", 722, 4}, \
	{25, "Chou", 723, 2}
};
int LengthTeacher = 5;
//...............................

struct student TabStudent[] = { 
	{11, "Jimmy", "0982123456", "1999-01-02", 1, 2},  \
	{21, "Albert", "0982123457", "1999-01-03", 2, 3}, \
	{31, "Charly", "0982123458", "1998-11-03", 2, 3}, \
	{41, "Denny", "0982123459", "1997-10-03", 2, 3},  \
	{51, "Ethan", "0945123459", "1967-09-03", 1, 3}, \
	{61, "Farra", "0944123459", "1937-08-03", 3, 4}, \
};
int LengthStudent = 6;
struct course TabCourse[] = {
	{1, "Computer Science", 3}, \
	{2, "Data Structure", 3}, \
	{3, "Digital System", 3}, \
	{4, "English Literature", 3}, \
};
int LengthCourse = 4;

int SearchStudent(int id) {
	int i;
	for (i = 0; i < LengthStudent; i++) if (id == TabStudent[i].sid) break;
	if (i >= LengthStudent) return -1; // -1 表示找不到ˋ這個學生 
	else return i;
}

void prsub2(int k) {
	int index;
	index = SearchStudent(k);
	if(index != -1)	printf("\n%s\t%s\t%s\t%s", TabStudent[index].birthday, \
		TabStudent[index].name, TabCourse[TabStudent[index].class1-1].name, \
		TabCourse[TabStudent[index].class2-1].name);
	else printf("\nCan't find this student!\n");
	//getchar();
}

void prsub1(int k) {
	int index;
	index = SearchStudent(k);
	if(index != -1)	printf("\n%s\t%s\t%d\t%d", TabStudent[index].birthday, \
		TabStudent[index].name, TabStudent[index].class1, TabStudent[index].class2);
	else printf("\nCan't find this student!\n");
	//getchar();
}

void prsub4() {
	int count[5];
	int i, j;
	for (i = 0; i < LengthCourse; i++) count[i + 1] = 0;
	for (i = 0; i < LengthStudent; i++) {
		count[TabStudent[i].class1] ++;
		count[TabStudent[i].class2] ++;
	}
	for (i = 0; i < LengthCourse; i++) printf("\nCourse %s has %d students.", \
		TabCourse[i].name, count[i+1]);
}

void pr_0322_1() { //列出各個老師所教導的學生名單
	int student_flag[100];
	int i, teacher_id, stu_id;
	for(teacher_id = 0; teacher_id < LengthTeacher; teacher_id++) {
		for(i = 0; i < LengthStudent; i++) student_flag[i] = 0;
		for(stu_id = 0; stu_id < LengthStudent; stu_id ++) {
			if(TabStudent[stu_id].class1 == TabTeacher[teacher_id].teaching) student_flag[stu_id] = 1;
			if(TabStudent[stu_id].class2 == TabTeacher[teacher_id].teaching) student_flag[stu_id] = 1;
		}
		printf("\nTeacher %s has taught:", TabTeacher[teacher_id].name);
		for(i = 0; i < LengthStudent; i++) if(student_flag[i]) printf("\t%s", TabStudent[i].name);
	}
}
void prsub5() { //老師名字及辦公室 
	for(int i = 1; i < LengthTeacher; i++){
		printf("\n%s\t%d", TabTeacher[i].name, TabTeacher[i].office);
	}
	
	//指定寫法 
	/*
	(int k) 
	for(int i = 0; i < LengthTeacher; i++){
		if(k == TabTeacher[i].tid)
			printf("\n%s\t%d", TabTeacher[i].name, TabTeacher[i].office);
	}
	*/
}

void prsub6(int k){ //各科目詢問辦公室 
	printf("\n%s", TabCourse[k-1].name);
	for(int i = 0; i < LengthTeacher; i++){
		if(TabTeacher[i].teaching == k){
			printf("\t%d", TabTeacher[i].office);
		}
	}
}

void prsub7(int k){ //各個老師所教導的學生數量
	int countStu = 0;
	int Teach;
	
	switch(k){
		case 22:
			Teach = 0;
			countStu = 6;
			break;
			
		case 23:
			Teach = 2;
			countStu = 2;
			break;
			
		case 99:
			Teach = 3;
			countStu = 1;
			break;
			
		case 25:
			Teach = 4;
			countStu = 4;
			break;
	}
	
	
	printf("\n%s has %d students.", TabTeacher[Teach].name, countStu);
	
}


int main() {
	prsub5();
	
	prsub6(1);
	prsub6(2);
	prsub6(3);
	prsub6(4);
	
	prsub7(22);
	prsub7(23);
	prsub7(99);
	prsub7(25);
	
	getchar();
}



