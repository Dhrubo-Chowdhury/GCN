#include <iostream>
using namespace std;

int main()
{
    int rowX, columnX, rowW, columnW, rowA, columnA, i, j, k;

    rowA = 1000;
    columnA = 1000;
    rowX = 1000;
    columnX = 1000;
    rowW = 1000;
    columnW = 1000;

    //Dynamically allocate memory for X, W and XW
    float** X = new float*[rowX];
    for(i = 0; i < rowX; i++)
        X[i] = new float[columnX];
    float** W = new float*[rowW];
    for(i = 0; i < rowW; i++)
        W[i] = new float[columnW];
    float** XW = new float*[rowX];
    for(i = 0; i < rowX; i++)
        XW[i] = new float[columnW];



    // Initializing elements of matrix X to 0.5
    for(i = 0; i < rowX; ++i)
        for(j = 0; j < columnX; ++j)
        {
            X[i][j] = 0.5;
        }

    // Initializing elements of matrix W to 0.1
    for(i = 0; i < rowW; ++i)
        for(j = 0; j < columnW; ++j)
        {
            W[i][j] = 0.1;
        }

    // Initializing elements of matrix XW to 0.
    for(i = 0; i < rowX; ++i)
        for(j = 0; j < columnW; ++j)
        {
            XW[i][j]=0;
        }

    // Multiplying matrix X and W and storing in array XW.
    for(i = 0; i < rowX; ++i)
        for(j = 0; j < columnW; ++j)
            for(k = 0; k < rowW; ++k)
            {
                XW[i][j] += X[i][k] * W[k][j];
            }

    //Displaying XW
    cout << endl << "XW: " << endl;
    for(i = 0; i < rowX; ++i)
        for(j = 0; j < columnW; ++j)
        {
            cout << " " << XW[i][j];
            if(j == columnW-1)
                cout << endl;
        }

    //Dynamically allocating memory for A and AXW
    float** A = new float*[rowA];
    for (int i = 0; i < rowA; ++i)
        A[i] = new float[columnA];
    float** AXW = new float*[rowA];
    for (i = 0; i < rowA; ++i)
        AXW[i] = new float[columnW];


    //fully connected adjacency matrix
    for(i = 0; i < rowA; ++i)
        for(j = 0; j < columnA; ++j)
        {
            A[i][j] = 1;
        }

    // Initializing elements of matrix AXW to 0.
    for(i = 0; i < rowA; ++i)
        for(j = 0; j < columnW; ++j)
        {
            AXW[i][j]=0;
        }

    //calculate AXW
    for(i = 0; i < rowA; ++i)
        for(j = 0; j < columnW; ++j)
            for(k = 0; k < columnA; ++k)
            {
                AXW[i][j] += A[i][k] * XW[k][j];
                //reLU
                if(AXW[i][j] < 0) AXW[i][j] = 0;
            }

    // Displaying AXW
    cout << endl << "AXW: " << endl;
    for(i = 0; i < rowA; ++i)
        for(j = 0; j < columnW; ++j)
        {
            cout << " " << AXW[i][j];
            if(j == columnW-1)
                cout << endl;
        }

    //freeing memory
    for (i = 0; i < rowX; ++i)
        delete [] X[i];
    delete [] X;

    for (i = 0; i < rowW; ++i)
        delete [] W[i];
    delete [] W;

    for (i = 0; i < rowX; ++i)
        delete [] XW[i];
    delete [] XW;

    for (i = 0; i < rowA; ++i)
        delete [] AXW[i];
    delete [] AXW;

    for (i = 0; i < rowA; ++i)
        delete [] A[i];
    delete [] A;

    return 0;
}
