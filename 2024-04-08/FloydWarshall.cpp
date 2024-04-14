void initialize(int W[][5], int D[][5], int Pi[][5])
{
    int n = 5;
    for(int i=0;i<n;i++)
    {
   	 for(int j=0;j<n;j++)
   	 {
   		 D[i][j] = W[i][j];
   		 if(i == j || W[i][j] > 999)
   			 Pi[i][j] = 0;
   		 else
   			 Pi[i][j] = i+1;
   	 }
    }
}

void floydWarshall(int D[][5], int Pi[][5])
{
    int n = 5;
    for(int k=0;k<n;k++)
    {
   	 for(int i=0;i<n;i++)
   	 {
   		 for(int j=0;j<n;j++)
   		 {
   			 if(Pi[i][k] != 0 && Pi[k][j] != 0 && D[i][j] > (D[i][k] + D[k][j]))
   			 {
   				 D[i][j] = D[i][k] + D[k][j];
   				 Pi[i][j] = Pi[k][j];
   			 }
   		 }
   	 }
    }
}

int main(void)
{
    int W[5][5],D[5][5],Pi[5][5];
    cout<<"Enter input matrix:\n";
    for(int i=0;i<5;i++)
    {
   	 for(int j=0;j<5;j++)
   		 cin>>W[i][j];
    }
    initialize(W,D,Pi);
    floydWarshall(D,Pi);
    cout<<"D matrix:\n";
    for(int i=0;i<5;i++)
    {
   	 for(int j=0;j<5;j++)
   		 cout<<D[i][j]<<"\t";
   	 cout<<endl;
    }
    cout<<"Pi matrix:\n";
    for(int i=0;i<5;i++)
    {
   	 for(int j=0;j<5;j++)
   		 cout<<Pi[i][j]<<"\t";
   	 cout<<endl;
    }
}
