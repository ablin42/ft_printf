char* conv(int nbHexa)
{ 
	char *bin; 
	int i; 
	size_t taille; 
	
	if(nbHexa<0) 
		return NULL; 
	i=1; 
	taille=0; 
	while(i<=nbHexa)
	{
		i<<=1; 
		taille++;
	}
	if(taille==0) 
		taille=1; 
	if((bin=malloc(taille))==NULL) 
		return NULL; 
	if(nbHexa==0) 
		bin[0]='0'; 
	while(nbHexa>0)
	{ 
		bin[--taille]=nbHexa % 2 + '0';
		nbHexa>>=1; 
	} 
	return bin;
}

int main(void)
{ 
	int nbHexa;
	char *bin; 

	puts("Nombre :"); 
	scanf("%x",&nbHexa); 
	printf("Conversion en binaire :%s\n",bin=conv(nbHexa)); 
	free(bin);
	bin=NULL; 
	return 0; 
}