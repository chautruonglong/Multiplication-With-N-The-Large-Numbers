// written by chautruonglong (mycodex).
// email: truonglongchau@gmail.com

#include<iostream>
#include<stdlib.h>
#include<string.h>

#define max 1000

using namespace std;

int charToNum(char n) {
	return n-48;
}

char numToChar(int n) {
	return n+48;
}

void init(char (*a)[max], int n) {
	for(int i=0; i<n; i++) {
		fflush(stdin);
		gets(a[i]);
	}
}

void out(char (*a)[max], int n) {
	for(int i=0; i<n; i++) {
		fflush(stdout);
		cout<<a[i]<<endl;
	}
}

char *multiplication(char (*a)[max], int);
char *times(char *, char *);
char *sumation(char *a[max], int);
char *sum(char *, char *);
int surplus(char *, int);
void moveElement(char *, int);
void addZero(char *, int);
void delZero(char *);

int main() {
	int n;
	char a[max][max];

	cout<<"How many is n? ";
	cin>>n;
	init(a, n);

	cout<<"Multiplication with "<<n<<" the numbers:\n";
	out(a, n);
	cout<<"Result = "<<multiplication(a, n);

	return 0;
}

char *multiplication(char (*a)[max], int n) {
	char *multi=a[0];

	for(int i=1; i<n; i++) {
		if(strlen(multi)>=strlen(a[i])) multi=times(multi, a[i]);
		else multi=times(a[i], multi);
	}
	delZero(multi);
	return multi;
}

char *times(char *a , char *b) {
	int sp, n=0;
	char *t[max];

	for(int i=strlen(b)-1; i>=0; i--, n++) {
		t[n]=(char*)calloc(max, sizeof(char));
		sp=0;
		for(int j=strlen(a)-1; j>=0; j--) sp=surplus(&t[n][j], sp+charToNum(a[j])*charToNum(b[i]));
		if(sp) moveElement(t[n], sp);
		addZero(t[n], n);
	}
	return sumation(t, n);
}

char *sumation(char *a[max], int n) {
	char *s=a[0];

	for(int i=1; i<n; i++) {
		if(strlen(s)>=strlen(a[i])) s=sum(s, a[i]);
		else s=sum(a[i], s);
	}
	return s;
}

char *sum(char *a , char *b) {
	int sp=0;
	char *s=(char*)calloc(max, sizeof(char));

	for(int i=strlen(b)-1, j=strlen(a)-1; i>=0; i--, j--) sp=surplus((s+j), sp+charToNum(a[j])+charToNum(b[i])); 
	for(int j=strlen(a)-strlen(b)-1; j>=0; j--) sp=surplus((s+j), sp+charToNum(a[j]));
	if(sp) moveElement(s, sp);
	return s;
}

int surplus(char *a, int s) {
	*a=numToChar(s%10);
	return s/10;
}

void moveElement(char *a, int sp) {
	for(int i=strlen(a); i>=1; i--) a[i]=a[i-1];
	a[0]=numToChar(sp);
}

void addZero(char *a, int n) {
	for(int i=n; i>0; i--) a[strlen(a)]='0';
}

void delZero(char *a) {
	while(a[0]=='0' && strlen(a)!=1) {
		for(int i=0; i<strlen(a)-1; i++) a[i]=a[i+1];
		a[strlen(a)-1]='\0';
	}
}