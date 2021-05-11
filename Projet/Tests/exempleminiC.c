extern int printd( int i );

/*----------------------------*/
/* un petit programme exemple
  pour montrer le langage miniC.*/
/*----------------------------*/

void printg(int k){}

int main() {
   int i, x;
   for (i=0; i<10; i=i+1) {
   	int k;
	if (i==5){
		printg(k);
	}
   }
   printd(i);
   return (i+3);
}

