
/****************************************### Passed Exam Version ###*****************************************/

 // O (N) -> Time Complexity
 // O (N) -> Space Complexity

#include <string.h>
#include <stdlib.h>
#define is_odd(c) ((c - '0') % 2)
#define max(a, b) (a > b ? a : b)

char    *longest_subarray(char *arr)
{
    int n = strlen(arr);
    int max_size = -1, start_index; 

	// Create an auxiliary array sunmleft[]. g
	// prefix_sum[i] will be sum of array 
	// elements from arr[0] to arr[i] 

	int prefix_sum[n]; 

	// For min and max values in prefix_sum[] 

	int min, max; 
	int i; 

	// Fill prefix_sum array and get min and max 
	// values in it. Consider 0 values in arr[] 
	// as -1 

	prefix_sum[0] = ((is_odd(arr[0])) ? -1 : 1); 
	min = arr[0]; max = arr[0]; 
	for (i=1; i<n; i++) 
	{	 
		prefix_sum[i] = prefix_sum[i-1] + ((is_odd(arr[i]) ? -1 : 1)); 
		if (prefix_sum[i] < min) 
			min = prefix_sum[i]; 
		if (prefix_sum[i] > max) 
			max = prefix_sum[i]; 
	} 

	// Now calculate the max value of j - i such 
	// that prefix_sum[i] = prefix_sum[j]. The idea is 
	// to create a hash table to store indexes of all 
	// visited values. 
	// If you see a value again, that it is a case of 
	// prefix_sum[i] = prefix_sum[j]. Check if this j-i is 
	// more than max_size. 
	// The optimum size of hash will be max-min+1 as 
	// these many different values of prefix_sum[i] are 
	// possible. Since we use optimum size, we need 
	// to shift all values in prefix_sum[] by min before 
	// using them as an index in hash[]. 

	int hash[max-min+1]; 

	// Initialize hash table 

	for (i=0; i<max-min+1; i++) 
		hash[i] = -1; 

	for (i=0; i<n; i++) 
	{ 
		// Case 1: when the subarray starts from 
		//		 index 0 

		if (prefix_sum[i] == 0) 
		{ 
		max_size = i+1; 
		start_index = 0; 
		} 

		// Case 2: fill hash table value. If already 
		//		 filled, then use it 

		if (hash[prefix_sum[i]-min] == -1) 
			hash[prefix_sum[i]-min] = i; 
		else
		{ 
			if ((i - hash[prefix_sum[i]-min]) > max_size) 
			{ 
				max_size = i - hash[prefix_sum[i]-min];
				start_index = hash[prefix_sum[i]-min] + 1; 
			} 
		} 
	} 

    if(max_size == -1)
    {
        char *r = (char *)malloc(sizeof(char) * 1);
        r[0] = '\0';
        return r;
    }
    char *r = (char *)malloc(sizeof(char) * (max_size + 1));
    int j;    
    for(i = start_index, j = 0; i < start_index + max_size; i++, j++)
        r[j] = arr[i];
    r[j] = '\0';
    return r;

}

// #include <stdio.h>
// int main (int ac, char **av)
// {
//     if(ac == 2)
//     {
//         printf("%s", longest_subarray(av[1]));
//     }
//     printf("\n");
//     return 0;
// }


// // Good TEST CASES

// Input : 1
// 0  | cat -e    
// Output :
// $

// Input : 2
// 110 | cat -e
// Output :
// 10$

// Input : 3
// c | cat -e
// Output :
// 0110$

// Input : 4
// 42424221422124332536547 | cat -e
// Output :
// 1422124332536547$

// Input : 5
// 222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222202222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222202222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222223222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222122222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222220222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222253222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222322222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222292222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222 | cat -e
// Output :
// 2253$

// Input : 6
// 4865312337864531297864531228978645312879645318879645312874531201268789787964531278964531255641522916874587917858871787151758456242481414681728786541813727148728154418354144157175151715714144477414141434534343885584541781681688468695584899484828246824685814646836845656446646464546565446586468384142356453687685368345687383738464189468628346884683484814646846846846447678568145814248141468172878654181372714872815441835414415717515171571414447741414143453434388558454178168168846869558489948482824682468581464683684565644664646454656544658646838414235645368768536834568738373846418946862834688468348481464684684684644761728786541813727148728154418354144157175151715714144477414141434534343885584541781681688468695584899484828246824685814646836845656446646464546565446586468384142356453687685368345687383738464189468628346884683484814646846846846447678568147287865418137271487281544183541441571751517157141444774141414345343438855845417816816884686955848994848282468246858146468368456564466464645465654465864683841423564536876853683456873837384641894686283468846834848146468468468464476785681458142481414681728786541813727148728154418354144157175151715714144477414141434534343885584541781681688468695584899484828246824685814646836845656446646464546565446586468384142356453687685368345687383738464189468628346884683484814646846846846447617287865418137271487281544183541441571751517157141444774141414345343438855845417816816884686955848994848282468248145814248141468172878654181372714872815441835414415717515171571414447741414143453434388558454178168168846869558489948482824682468581464683684565644664646454656544658646838414235645368768536834568738373846418946862834688468348481464684684684644761728786541813727148728154418354144157175151715714144477414141434534343885584541781681688468695584899484828246824685814646836845656446646464546565446586468384142356453687685368345687383738464189468628346884683484814646846846846447678568147287865418137271487281544183541441571751517157141444774141414345343438855845417816816884686955848994848282468246858146468368456564466464645465654465864683841423564536876853683456873837384641894686283468846834848146468468468464476785 | cat -e
// Output :
// 53123378645312978645312289786453128796453188796453128745312012687897879645312789645312556415229168745879178588717871517584562424814146817287865418137271487281544183541441571751517157141444774141414345343438855845417816816884686955848994848s2824682468581464683$

// Input : 7
// 2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222212222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222225222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222322222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222292222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222 | cat -e
// Output :
// 21$


// Input : 8
// 79135790246802 | cat -e
// Output :
// 79135790246802$
