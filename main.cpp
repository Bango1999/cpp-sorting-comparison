#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

//------------------------------------------------------------------
// Initialize data array with random values between 0 and range-1
//------------------------------------------------------------------
const int num=100;

void random_data(int data[], int count, int range)
{
    //remove line below to make it not random every time.
    srand(time(NULL));
   // Put specified count of random numbers into data array
   for (int index = 0; index < count; index++)
   {
      
      data[index] = rand() % range;
   }
}
//------------------------------------------------------------------
// Shuffle data values inside data array 
//------------------------------------------------------------------
//data, 0, num
void shuffle_data(int data[], int count, int shuffles)
{
   // Shuffle data by swapping random pairs of values
   for (int index = 0; index < shuffles; index++)
   {
      int pos1 = rand() % count;
      int pos2 = rand() % count;
      int temp = data[pos1];
      data[pos1] = data[pos2];
      data[pos2] = temp;
   }
}
//------------------------------------------------------------------
// Write data array to output file
//------------------------------------------------------------------
void write_data(string name, int data[], int count)
{
   // Open output file
   ofstream dout;
   dout.open(name.c_str());
   if (dout.fail())
      cout << "Error: could not open output file\n";

   // Write the data
   dout << count;
   for (int i = 0; i < count; i++)
   {
      if (i % 20 == 0)
	 dout << endl;
      dout << data[i] << " ";

   }

   // Close the file 
   dout.close();
}
//-----------------------------------------------------------------
// Bubble sort algorithm
//-----------------------------------------------------------------
void corn_sort(int data[], int count)
{
   int pass = 1;
   int exchange = 1;
   int direction = (pass % 2); //tells if pass is odd or even
   
   // Bubble largest value to the right N times
   if (direction == 1) {
       
   //VALUE IS 1, SO GO FORWARDS
   while ((pass < count) && (exchange > 0))
   {
      // Scan unsorted part of data array
      exchange = 0; //this is made to 1, and increments after that to record number of exchanges in this pass
      //if exchange != 0, then the lop needs to continue on because there are still errors
      //if exchange = 0, then the data is sorted and the loop can exit
	    for (int index = 0; index < count - pass; index++)
	    {

	       // Swap two data values if out of order
	       if (data[index] > data[index + 1])
	       {
		  int temp = data[index];
		  data[index] = data[index + 1];
		  data[index + 1] = temp;
		  exchange++;
	       }
	    }
       }
       
   } else {
    
       
       
       //VALUE IS 0, SO WORK BACKWARDS
       while ((count < pass) && (exchange > 0))
   {
  
       
       
	   
      // Scan unsorted part of data array
      exchange = 0; //this is made to 1, and increments after that to record number of exchanges in this pass
      //if exchange != 0, then the lop needs to continue on because there are still errors
      //if exchange = 0, then the data is sorted and the loop can exit
      for (int index = count-1; index > 0 - pass; index--)
      {
	  
	 // Swap two data values if out of order
	 if (data[index] < data[index + 1])
	 {
	    int temp = data[index];
	    data[index] = data[index + 1];
	    data[index + 1] = temp;
	    exchange++;
	 }
      }
       
   }
       pass++;
   }
}


void print_data(int data[], string sortmethod) {
    cout << endl << "SORT METHOD = " << sortmethod << endl;
    for (int i = 0; i < num; i++) {
	cout << "Data[" << i << "] = " << data[i] << endl;
    }
}

//---------------------------------------------------------------
// Selection sort algorithm
//---------------------------------------------------------------
//                  data[]      0        num=5
void hilow_sort(int data[], int low, int high)
{

    
    
    int counter = 0;
    
    //loop num times
int lowCounter = low;
int highCounter = high-1;
    while (lowCounter <= highCounter) {
	//cout << "looping through the big while" << endl;

//	print_data(data,"");
	
	int lowestNumberIndex = lowCounter;
	int highestNumberIndex = highCounter;
	//int lowCounter = low; //counter
	//int highCounter = high-1; //counter
	int index = lowCounter;
	//int indexMax = 
	//cout << "lowCounter="<<lowCounter<<endl;
	//cout << "highCounter="<<highCounter<<endl;
//cout << lowcounter<<"<"<<high/2<<endl;
	while (index <= highCounter) {
	//cout<<"index="<<index<<endl;
		//cout << "lowCounter="<<lowCounter<<endl;
		//cout<<"highCounter="<<highCounter<<endl;
	        //cout << lowCounter<<"<"<<high/2<<endl;

	  //  cout<<"checking data[index] <= data[lowestNumberIndex] and <= data[lowcounter]"<<endl;
	//	cout<<data[index]<< "<=" << data[lowestNumberIndex] << "and <=" << data[lowCounter]<<endl;
	    if (data[index] <= data[lowestNumberIndex] && data[index] <= data[lowCounter]) {
		lowestNumberIndex = index;
	//	cout<<"true, replacing lowestNumberIndex = " << index<<endl;
	    }
		//cout<<"checking data[index] >= data[highCounter"<<endl;
		//cout<<data[index]<< ">=" <<data[highCounter]<<endl;
	    if (data[index] >= data[highestNumberIndex] && data[index] >= data[highCounter]) {
		highestNumberIndex = index;
		//cout<<"true, replacing highestNumberIndex = "<<index<<endl;
	    }
		index++;
	
	}
	  //  cout<<"lowestNumberIndex="<<lowestNumberIndex<<" lowestNum="<<data[lowestNumberIndex]<<endl;
	//	cout <<"highestNumberIndex="<<highestNumberIndex<<" highestNum="<<data[highestNumberIndex]<<endl<<endl;
	    
	    
	    
	    //temp swithing
//	cout<<"temp1="<<data[lowestNumberIndex]<<endl;
	    int temp1 = data[lowestNumberIndex];
//	cout<<"data[lowestNumberIndex="<<data[lowCounter]<<endl;
	    data[lowestNumberIndex] = data[lowCounter];
//	cout<<"data[lowCounter]="<<temp1<<endl<<endl;
	    data[lowCounter] = temp1;
	    
//	cout<<"temp2="<<data[highestNumberIndex]<<endl;
	    int temp2 = data[highestNumberIndex];
//	cout<<"data[highestNumberIndex]="<<data[highCounter]<<endl;
	    data[highestNumberIndex] = data[highCounter];
//	cout<<"data[highCounter]="<<temp2<<endl<<endl;
	    data[highCounter] = temp2;


	lowCounter++;
	highCounter--;
	counter++;

	}

}
int main()
{
    int data[num];
    
    //shuffle
    random_data(data, num, 999);
    shuffle_data(data, num, 20);
    print_data(data, "random and shuffled");
    
    //bubble
    corn_sort(data, num);
    print_data(data, "corn sorted");
    
    //selection
    shuffle_data(data, num, 20);
    print_data(data, "random and shuffled again");
    hilow_sort(data, 0, num);
    print_data(data, "hilow sort");

    //shuffle_data(int data[], int count, int shuffles)
    //write_data("random.txt", data, num);
    //write_data("shuffle.txt", data, num);

    return 0;
}
