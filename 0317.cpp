// This program is used in Data Base Class on 3/8 and 3/15
// For Practice of Pr4 on 2021/3/8
#include <stdio.h>
#include <string.h>

struct student {
	int sid;
	char name[100], phone[20], birthday[20];
	int class1, class2; // 修課，寫入課程標號 
};

struct course {
	int cid;
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
// possible problem for db02.c
/*
列出老師的名字和其辦公室。
列出各科目的詢問辦公室。
列出各個學生可能要去詢問問題的辦公室。
列出各個老師所教導的學生數量。
列出各個老師所教導的學生名單。
*/
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

prsub2(int k) {
	int index;
	index = SearchStudent(k);
	if(index != -1)	printf("\n%s\t%s\t%s\t%s", TabStudent[index].birthday, \
		TabStudent[index].name, TabCourse[TabStudent[index].class1-1].name, \
		TabCourse[TabStudent[index].class2-1].name);
	else printf("\nCan't find this student!\n");
	//getchar();
}

prsub1(int k) {
	int index;
	index = SearchStudent(k);
	if(index != -1)	printf("\n%s\t%s\t%d\t%d", TabStudent[index].birthday, \
		TabStudent[index].name, TabStudent[index].class1, TabStudent[index].class2);
	else printf("\nCan't find this student!\n");
	//getchar();
}

prsub4() {
	int count[5];
	int i, j;
	for (i = 0; i < LengthCourse; i++) count[i + 1] = 0;
	for (i = 0; i < LengthStudent; i++) {
		count[TabStudent[i].class1] ++;
		count[TabStudent[i].class2] ++;
	}
	for (i = 0; i < LengthCourse; i++) printf("\nCourse %s has %d students.\tCourse id is %d.", \
		TabCourse[i].name, count[i+1], TabCourse[i].cid);
}

prsub5(int k) {
	int count[5]; //學生數量
	int i, j;
	for (i = 0; i < LengthCourse; i++) count[i + 1] = 0;
	for (i = 0; i < LengthStudent; i++) {
		count[TabStudent[i].class1] ++;
		count[TabStudent[i].class2] ++;
	}
	
	int m;
	for(m = 0; m < LengthStudent; m++){
		if(TabStudent[m].class1 == k || TabStudent[m].class2 == k){
		printf("\n%d\t%s", TabStudent[m].sid, TabStudent[m].phone);
		}
	}
}

main() {
	prsub2(61);
	prsub5(2);
	prsub4();
	getchar();
}
