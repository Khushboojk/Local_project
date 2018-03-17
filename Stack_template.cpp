#include <iostream>
using namespace std;

template< typename T>
class stack{
	private :
		T *sptr;
		int size;
		int ptop=-1;
	public:
		explicit stack(int s=1)
		{
			size = s;
			sptr = new T[size];
		}
		
		void push(T data)
		{
			if(ptop == size-1)
			{
					int	nsize = 2*size;
					T *nptr = new T[nsize];
					for(int i=0; i<size; i++)
					{
						nptr[i]=sptr[i];	
					}
					free(sptr);
					sptr=nptr;
					size=nsize;
					// free(nptr);
					
			}
			ptop = ptop+1;
			sptr[ptop]=data;
				
			
			
		}
		void pop()
		{
			if(ptop==-1)
			{
				cout<<"Underflow"<<endl;
				// return NULL;
			}
			else
			{
				// T ans = sptr[ptop];
				ptop = ptop-1;
				// return ans;
				if(ptop+1==size/2)
				{
					int	nsize = size/2;
					T *tptr = new T[nsize];
					for(int i=0; i<nsize; i++)
					{
						tptr[i]=sptr[i];	
					}
					free(sptr);
					sptr=tptr;
					size=nsize;
					// free(tptr);
				}
				
			}
		}
		T top()
		{
			if(ptop==-1)
			{
				cout<<"Underflow"<<endl;
				return NULL;
			}
			else
			{
				return sptr[ptop];
			}
		}
		
		int length()
		{
			return ptop+1;
			
		}
};

int main() {
	// your code goes here

	stack<int> st;
	st.push(1);
	cout<<st.top()<<endl;
	st.push(2);
	cout<<st.top()<<endl;
	st.pop();
	cout<<st.top()<<endl;
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	st.push(7);
	cout<<st.length()<<endl;
	stack<char> sc;
	
	
	sc.push('a');
	sc.push('b');
	sc.pop();
	cout<<sc.top()<<endl;
	sc.push('c');
	sc.push('d');
	sc.push('e');
	sc.push('f');
	// sc.push('g');
	cout<<sc.length()<<endl;
	
	
	return 0;
}