/*

    Time complexity: O(N*log(N))

    Space complexity: O(N)



    Where N is number of elements in array.

*/



void mergeSort(vector < int > & arr, int n) {

    int currentGap = 2;



    // Nearest power of 2 which is greater then or equal to n.

    float nearestPowerTwo = log2(n);

    if (int(nearestPowerTwo) != (nearestPowerTwo)) {

        nearestPowerTwo = pow(2, int(nearestPowerTwo) + 1);

    } 

    else {

        nearestPowerTwo = pow(2, int(nearestPowerTwo));

    }



    int parts;

    while (currentGap <= nearestPowerTwo) {



        // Divide 'n' size list in 'n/currentGap' parts.

        parts = n / currentGap;

        if (n % currentGap != 0) {

            parts++;

        }

        for (int i = 0; i < parts; i++) {



            /*

                Divide every part in two section and merge them in sorted manner.

                'ptrLeft' is starting indices of current part

                'ptrRight' is middle indices of current part

                'end' is ending+1 indices of current part.

            */

           

            int ptrLeft = i * currentGap;

            int copyLeft = ptrLeft;

            int end = (i + 1) * currentGap;

            int ptrRight = (ptrLeft + end) / 2;

            end = min(end, n);

            int copyRight = ptrRight;

            vector < int > mergeArr;

            while (ptrLeft <= copyRight and ptrRight < end) {

                if (arr[ptrLeft] > arr[ptrRight]) {

                    mergeArr.push_back(arr[ptrRight]);

                    ptrRight += 1;

                } else {

                    mergeArr.push_back(arr[ptrLeft]);

                    ptrLeft += 1;

                }



                if (ptrLeft == copyRight) {

                    while (ptrRight != end) {

                        mergeArr.push_back(arr[ptrRight]);

                        ptrRight++;

                    }

                    break;

                }

                if (ptrRight == end) {

                    while (ptrLeft != copyRight) {

                        mergeArr.push_back(arr[ptrLeft]);

                        ptrLeft++;

                    }

                    break;

                }

            }



            // Copy the 'mergeArr' in actual 'arr'.

            for (int i = 0; i < mergeArr.size(); i++) {

                arr[copyLeft + i] = mergeArr[i];

            }

        }

        currentGap *= 2;

    }



}
