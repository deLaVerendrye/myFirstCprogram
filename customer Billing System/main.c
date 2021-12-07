#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <windows.h>


char usernameReg[50];
char passwordReg[50];
char emailReg[50];
char nameReg[50];
char ccNumReg[50];

char RecovQuestion[500];
char Answer[100];
char currentDate[] = __DATE__;

char username[50];
char password[50];
char email[50];
char name[50];
int balance;
char ccNum[50];
char balanceTXT[] = "Balance.txt";

int deleteAcc(){
    HANDLE hConsole;hConsole=GetStdHandle
    (STD_OUTPUT_HANDLE);
    bool isDone = false;
    char ch;
    char confirmationPass[50];
    char confirmationUsrnm[50];
    char usrnmCheck[50];
    char filename[50];
    char nLine[50];
    char rLine[50];

    while( !isDone ){
    system("cls");
    printf("\n\n\n\n                                        Do you really want to delete your account? Y/N\n");
    ch = getch();
    fflush(stdin);

    system("cls");

    if( ch == 'Y' || ch == 'y' ){
        printf("\n\n\n\n                                         Enter your username first: ");
        fgets(confirmationUsrnm, 50, stdin);
        fflush(stdin);

        FILE* Ffirst = fopen("registeredAcc.dat", "r");

        while( !isDone ){

        fgets(usrnmCheck, 50, Ffirst);

        strcpy(nLine, usrnmCheck);

        if( strcmp( confirmationUsrnm, usrnmCheck )==0 ){
            printf("\n                                         and your password: ");
            fgets(confirmationPass, 50, stdin);
            fflush(stdin);

            fgets(usrnmCheck, 50, Ffirst);
            fclose(Ffirst);

            if( strcmp( confirmationPass, usrnmCheck )==0 ){

                bool isDeleted = false;
                char newLine[50];
                char recentLine[50];

                FILE* fRA = fopen( "registeredAcc.dat", "r" );
                FILE* fTF = fopen( "temp.txt", "w");

                while(!isDeleted){
                    fgets( newLine, 50, fRA);
                    if(  strcmp(recentLine, newLine)==0 ){
                        break;
                    }
                    else if(strcmp(confirmationUsrnm, newLine)==0)
                    {
                        for(int i=0; i<6; i++){ fgets(newLine, 50, fRA); }
                    }
                    else{ strcpy(recentLine, newLine); fprintf(fTF, "%s", newLine); }

                }

                fclose(fRA);
                fclose(fTF);


                FILE* fnewRA = fopen("registeredAcc.dat", "w");
                FILE* fnewTF = fopen("temp.txt", "r");

                while( !isDeleted ){
                    fgets( newLine, 50, fnewTF );
                    if( strcmp( recentLine, newLine )==0){
                        break;
                    }
                    else{
                        fprintf(fnewRA, "%s", newLine);
                        strcpy(recentLine, newLine);
                    }
                }

                fclose(fnewRA);
                fclose(fnewTF);

                sprintf(filename, "%sBalance.dat", username);
                remove(filename);
                sprintf(filename, "%sTH.dat", username);
                remove(filename);
                remove("temp.txt");



                system("cls");
                SetConsoleTextAttribute(hConsole, 10);
                printf("\n\n\n\n                                         Your account has been successfully deleted\n");
                SetConsoleTextAttribute(hConsole, 11);
                getch();
                fflush(stdin);
                system("cls");
                return 0;

            }
            else{
            SetConsoleTextAttribute(hConsole, 12);
            printf("\n                                         Incorrect password\n");
            SetConsoleTextAttribute(hConsole, 11);
            getch();
            fflush(stdin);
            system("cls");
            return 1;
            }


        }
        else if(strcmp( rLine, nLine )==0){
        isDone = true;
        }

        strcpy(rLine, nLine);
        }

        SetConsoleTextAttribute(hConsole, 12);
        printf("\n                                         That is not your username!!\n");
        SetConsoleTextAttribute(hConsole, 11);
        getch();
        fflush(stdin);
        system("cls");
        return 1;

    }
    else if( ch == 'N' || ch == 'n'){
        return 1;
    }
    else{
        SetConsoleTextAttribute(hConsole, 12);
        printf("\n\n\n\n\n\n                                         Invalid");
        SetConsoleTextAttribute(hConsole, 11);
        getch();
        fflush(stdin);
    }
    }

}


int transactionHS(){
    system("cls");

    char filename[50];
    char recentLine[100];
    char newLine[100];
    bool isEmpty = false;

    printf("\n                                          ---------------------------------------");
    printf("\n                                           _  __ ____  ___  ____  __  ____  _   _");
    printf("\n                                           ||_||  ||  ||__   ||  //\\\\ ||_|| \\\\_//");
    printf("\n                                           || || _||_  __||  ||  \\\\// || \\\\   //");
    printf("\n                                          ---------------------------------------\n");


    FILE* fPhistory;

    sprintf( filename, "%sTH.dat", username);

    fPhistory = fopen( filename, "r" );

    while( !isEmpty ){
    fgets(newLine, 100, fPhistory);

    if( (strcmp(recentLine, "--------------------------------------\n") == 0) && (strcmp(newLine, "--------------------------------------\n")== 0) ){
        isEmpty = true;
    }
    else if( ( strcmp(recentLine, "") == 0) && ( strcmp(newLine, "") == 0) ){
        printf("            No transactons");
        isEmpty = true;
    }

    strcpy(recentLine, newLine);
    if( !isEmpty ){
    printf("\n                                          %s", newLine);
    }
    }

    fclose(fPhistory);

    getch();
    fflush(stdin);
    system("cls");
    return 0;
}


int orderSnacks(){
    HANDLE hConsole;hConsole=GetStdHandle
    (STD_OUTPUT_HANDLE);

    system("cls");
    char filename[50];
    char orders[50][20];
    int i;
    int n;
    int orderPrices[50];
    int orderQuantity[50];
    int orderTotal = 0;
    int priceByQuantity[50];
    bool isAvailable = false;


    while(!isAvailable){

    n = 0;
    system("cls");
    printf("\n\n                                    ___  ____  ____  ____ ____");
    printf("\n                                   // \\\\ ||_|| || \\\\ ||__ ||_||");
    printf("\n                                   \\\\_// || \\\\ ||_// ||__ || \\\\");
    printf("\n                                   ----------------------------");

    printf("\n\n                                  *************Welcome to FORTRAN store*************\n");
    printf("                                  ******                               *************\n");
    printf("                                  ******     Snickers - 55.00          *************\n");
    printf("                                  ******     Barnuts - 28.00           *************\n");
    printf("                                  ******     Pretzels - 150.00         *************\n");
    printf("                                  ******     Doritos - 275.00          *************\n");
    printf("                                  ******     Lifesavers - 50.00        *************\n");
    printf("                                  ******     Butterfingers - 299.00    *************\n");
    printf("                                  ******     Snowbear - 122.00         *************\n");
    printf("                                  ******     Caramello - 205.00        *************\n");
    printf("                                  ******     Pringles - 90.00          *************\n");
    printf("                                  ******                               *************\n");

    printf("\n                         Type your food selection below ( Type done to confirm order selection )\n");

    printf("\n                         ");

    for(i=0; i<11; i++){
        scanf("%s", orders[i]);

        if( strcmp(orders[i], "Done") == 0 || strcmp(orders[i], "done") == 0 ){ i = 12; }
        else if( strcmp(orders[i], "Cancel") == 0 || strcmp(orders[i], "cancel") == 0 ){
            system("cls");
            return 0;
        }
        n++;
    }

    for(i=0; i < n-1; i++){

        if(strcmp(orders[i], "Snickers")==0 || strcmp(orders[i], "snickers")==0 ){ orderPrices[i] = 55; isAvailable = true;}
        else if(strcmp(orders[i], "Barnuts")==0 || strcmp(orders[i], "barnuts")==0 ){ orderPrices[i] = 28; isAvailable = true;}
        else if(strcmp(orders[i], "Pretzels")==0 || strcmp(orders[i], "pretzels")==0 ){ orderPrices[i] = 150; isAvailable = true;}
        else if(strcmp(orders[i], "Doritos")==0 || strcmp(orders[i], "doritos")==0 ){ orderPrices[i] = 275; isAvailable = true;}
        else if(strcmp(orders[i], "Lifesavers")==0 || strcmp(orders[i], "lifesavers")==0 ){ orderPrices[i] = 50; isAvailable = true;}
        else if(strcmp(orders[i], "Butterfingers")==0 || strcmp(orders[i], "butterfingers")==0 ){ orderPrices[i] = 299; isAvailable = true;}
        else if(strcmp(orders[i], "Snowbear")==0 || strcmp(orders[i], "snowbear")==0 ){ orderPrices[i] = 122; isAvailable = true;}
        else if(strcmp(orders[i], "Caramello")==0 || strcmp(orders[i], "caramello")==0 ){ orderPrices[i] = 205; isAvailable = true;}
        else if(strcmp(orders[i], "Pringles")==0 || strcmp(orders[i], "pringles")==0 ){ orderPrices[i] = 90; isAvailable = true;}
        else { SetConsoleTextAttribute(hConsole, 14); printf("\n                         Your selection the %s is not available, please check the list above\n\n", orders[i]); SetConsoleTextAttribute(hConsole, 11); isAvailable = false; getch(); fflush(stdin); i = n+1;}

        }

    }

    for(i=0; i < n-1; i++){
        printf("\n                            How many %s will you order: ", orders[i]);
        scanf("%d", &orderQuantity[i]);
    }

    system("cls");

    for(i=0; i < n-1; i++){
        priceByQuantity[i] = orderPrices[i]*orderQuantity[i];
    }

    for( i=0; i < n-1; i++ ){
        orderTotal += priceByQuantity[i];
    }

    if( orderTotal > balance ){
        SetConsoleTextAttribute(hConsole, 14);
        printf("\n\n\n\n                               Looks like your balance is not enough to make this purchase\n");
        printf("                               Please check your balance or cash-in to continue shoppin ");
        SetConsoleTextAttribute(hConsole, 11);
        getch();
        fflush(stdin);
        return 0;
    }

    balance -= orderTotal;

    printf("\n\n\n                                             RECEIPT         \n");
    printf("                                   client name: %s", name);
    printf("                                   email: %s\n\n", email);

    for(i=0; i < n-1; i++){
        printf("                                  %s x%d...................PHP %d.00\n", orders[i], orderQuantity[i], priceByQuantity[i]);
    }
    printf("\n                                  total cost...................PHP %d.00\n", orderTotal);



    FILE* fPayment;

    sprintf( filename, "%sBalance.dat", username);

    fPayment = fopen( filename, "w" );

    fprintf( fPayment, "%d", balance );

    fclose(fPayment);

    ///NEEW FEATURE!!!


    FILE* fUsrReceipt;

    sprintf( filename, "%sTH.dat", username);

    fUsrReceipt = fopen( filename, "a" );

    fprintf(fUsrReceipt, "            ORDER SNACKS\n");
    fprintf(fUsrReceipt, "Date: %s\n", currentDate);
    for(i=0; i < n-1; i++){
    fprintf(fUsrReceipt, "%s x%d...................PHP %d.00\n", orders[i], orderQuantity[i], priceByQuantity[i]);
    }
    fprintf(fUsrReceipt, "total cost...................PHP %d.00\n", orderTotal);
    fprintf(fUsrReceipt, "Balance after purchase: PHP %d.00\n", balance);
    fprintf(fUsrReceipt, "--------------------------------------\n");

    fclose(fUsrReceipt);

    ///--------------------------------------------

	getch();
    fflush(stdin);

    return 0;
}


int deposit(){
    HANDLE hConsole;hConsole=GetStdHandle
    (STD_OUTPUT_HANDLE);
    int depositAmount;
    char filename[50];
    char ccNumCheck[50];
    bool ccNumCorrect = false;


    while( !ccNumCorrect ){
    system("cls");
    printf("\n\n\n\n\n                                          Enter deposit amount: ");
    SetConsoleTextAttribute(hConsole, 10);
    scanf( "%d", &depositAmount );
    SetConsoleTextAttribute(hConsole, 11);
    printf("\n                                     Enter your credit card number: ");
    fflush(stdin);
    fgets( ccNumCheck, 50, stdin );
    fflush(stdin);


    if( strcmp( ccNumCheck, "Cancel\n" ) == 0 || strcmp( ccNumCheck, "cancel\n" ) == 0 ){
        system("cls");
        return 0;

    }
    else if( strcmp( ccNumCheck, ccNum ) != 0 ){
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        printf("\n\n\n\n                                          That is not your credit card number!!");
        SetConsoleTextAttribute(hConsole, 11);
        getch();
        fflush(stdin);
    }
    else{
        ccNumCorrect = true;
    }
    }


    balance += depositAmount;


    FILE* fDeposit;

    sprintf( filename, "%sBalance.dat", username);

    fDeposit = fopen( filename, "w" );

    fprintf( fDeposit, "%d", balance );

    fclose(fDeposit);

    ///-------------------------------------

    FILE* fUsrReceipt;

    sprintf( filename, "%sTH.dat", username);

    fUsrReceipt = fopen(filename, "a");

    fprintf(fUsrReceipt, "               CASH IN\n");
    fprintf(fUsrReceipt, "Date: %s\n", currentDate);
    fprintf(fUsrReceipt, "Deposit Amount: %d.00\n", depositAmount);
    fprintf(fUsrReceipt, "Balance after deposit: PHP %d.00\n", balance);
    fprintf(fUsrReceipt, "--------------------------------------\n");

    fclose(fUsrReceipt);


    printf("\n\n                              You have successfully deposited ");
    SetConsoleTextAttribute(hConsole, 10);
    printf("Php%d ", depositAmount);
    SetConsoleTextAttribute(hConsole, 11);
    printf("to your account");
    getch();
    fflush(stdin);
    system("cls");

    return 0;


}


/// Forget Password Function

int forgetPassword(){
    HANDLE hConsole;hConsole=GetStdHandle
    (STD_OUTPUT_HANDLE);
    int i;
    char user[50];
    char checker[500];
    char recovAnswer[100];
    char recovPass[50];
    char recentLine[50];
    bool isEmpty = false;

    fflush(stdin);
    printf("\n\n\n\n\n                                          Enter username: ");
    fgets(user, 50, stdin);
    fflush(stdin);


    /// Opening the registeredAcc.txt file
    FILE* fOpen = fopen("registeredAcc.dat", "r");


    /// Checking every lines of the txt file if the username exist's
    /// Putting 100 as loop count is not neccessary it depends on the number of the users
    while(!isEmpty){
        fgets(checker, 50, fOpen);

        /// if ang username na ge input kay mag match with one of the line in the txt file
        /// it will execute the codes in this if statement
        if( strcmp( user, checker)==0 ){

            system("cls");
            for(i = 0; i<5; i++){
                fgets(checker, 50, fOpen);
                if( i == 2 ){
                    printf("\n\n\n\n                                          Hello %s                               Please answer the question to recover your password\n", checker);
                }else if( i == 0 ){
                    strcpy(recovPass, checker);
                }
            }

            printf("\n                                          %s\n", checker);
            printf("\n\n                                          ans:", checker);
            fgets(recovAnswer, 50, stdin);
            fflush(stdin);

            fgets(checker, 100, fOpen);

            if ( strcmp(recovAnswer, checker) == 0 ){
                SetConsoleTextAttribute(hConsole, 10);
                printf("\n                                      Your password is: %s", recovPass);
                SetConsoleTextAttribute(hConsole, 11);
                getch();
                fflush(stdin);
                system("cls");
                return 0;
            }
            SetConsoleTextAttribute(hConsole, 12);
            printf("\n                                          incorrect!!");
            SetConsoleTextAttribute(hConsole, 11);
            getch();
            fflush(stdin);
            system("cls");
            return 0;
        }
        else if( strcmp( recentLine, checker )==0 ){ isEmpty = true; }

        strcpy(recentLine, checker);
    }

    /// Closing the file
    fclose(fOpen);


    /// If no line of text from the txt file above, the for loop will end,
    /// and will continue here
    system("cls");
    SetConsoleTextAttribute(hConsole, 12);
    printf("\n\n\n\n\n                               Sorry but that username you entered doesn't exist at our database");
    SetConsoleTextAttribute(hConsole, 11);
    getch();
    fflush(stdin);
    system("cls");
    return 0;
    /// return 0 ako gamit para mobalik sa main function
}



int Dashboard(){
    HANDLE hConsole;hConsole=GetStdHandle
    (STD_OUTPUT_HANDLE);
    system("cls");
    int res;
    char filename[50];
    int delAcc;
    bool Logout = false;

    FILE* fBalance;

    sprintf( filename, "%sBalance.dat", username);

    fBalance = fopen( filename, "r" );

    fscanf( fBalance, "%d", &balance );

    fclose(fBalance);


    while( !Logout ){
    system("cls");
    printf("\n\n\n\n                                  _      _ ___   _     ____   ___  _    __ ____");
    printf("\n                                  \\\\    // |__  ||    //     // \\\\ ||\\\//|| ||__");
    printf("\n                                   \\\\/\\//  |__  ||___ \\\\___  \\\\_// ||   || ||__");
    printf("\n                                   --------------------------------------------");
    printf("\n\n                                          Hello %s", name);
    printf("\n                                          What would you like to do?\n");
    printf("\n                                            [1]order snack \n                                            [2]Check balance \n                                            [3]Cash in \n"
           "                                            [4]Transaction History\n                                            [5]Delete Account\n                                            [6]Logout\n");
    printf("\n                                          res: ");
    scanf("%d", &res);

    if( res == 1 ){
        orderSnacks();
    }

    else if( res == 2 ){
        system("cls");
        printf("\n\n\n\n\n                                          Your balance is ");
        SetConsoleTextAttribute(hConsole, 10);
        printf("Php %d.00", balance);
        SetConsoleTextAttribute(hConsole, 11);
        getch();
        fflush(stdin);
    }

    else if ( res == 3 ){
        deposit();
    }
    else if( res == 4 ){
        transactionHS();
    }
    else if ( res == 5 ){
        delAcc = deleteAcc();
        if( delAcc == 0 ){
            return 0;
        }else if( delAcc == 1 ){
            Logout = false;
        }
        else{ printf("unexpected error occured"); getch(); fflush(stdin); exit(1);}
    }

    else if ( res == 6 ){
        Logout = true;
    }

    else{
        SetConsoleTextAttribute(hConsole, 12);
        printf("\n                                          Invalid response");
        SetConsoleTextAttribute(hConsole, 11);
        getch();
        fflush(stdin);
    }

    }

    return 0;
}

/// Login function

int Login(){
    HANDLE hConsole;hConsole=GetStdHandle
    (STD_OUTPUT_HANDLE);
    char accCheck[50];
    char recentLine[50];
    bool isEmpty = false;
    bool firstRepeat = false;
    int n = 1;
    int AE = 0;
    char ch;

    strcpy( password, " ");

    printf("\n\n\n\n                                        _     ___   ___   ____  __  __");
    printf("\n                                        ||   // \\\\ // __   ||   ||\\\ ||");
    printf("\n                                        ||__ \\\\_// \\\\_\\\\  _||_  || \\\||");
    printf("\n                                        -------------------------------");

    fflush(stdin);
    printf("\n\n                                       Enter username: ");
    //fgets(username, 50, stdin);
    scanf("%s", username);
    fflush(stdin);
    printf("\n                                       Enter password: ");


    for( int i = 0; i < n;){

    ch = getch();

    if( ch == 13 ){
        password[i] = '\n';
        break;
    }
    else if( ch == 8 && AE != 0){
        printf("\b \b");
        password[i] = "";
        i -= 1;
        AE -= 1;
    }
    else if( ch == 8 && AE == 0){
        printf("");
    }
    else{ printf("*"); password[i] = ch; AE++; n++; i++;}

    fflush(stdin);
    }

    fflush(stdin);

    FILE* fOpen = fopen("registeredAcc.dat", "r");

    while(!isEmpty){

        fscanf( fOpen, "%s", accCheck );

        /// Nested if statements
        if( strcmp(username, accCheck) == 0 ){

            fgets(accCheck, 50, fOpen);
            fgets(accCheck, 50, fOpen);

            /// if ang next line of text sa nag match na username sa txt file kay mo match sa password this if statement will execute
            if( strcmp( password, accCheck )==0 ){
                fgets(email, 50, fOpen);
                fgets(name, 50, fOpen);
                fgets(ccNum, 50, fOpen);
                fclose(fOpen);

                Dashboard();
                system("cls");
                return 0;
            }

            /// if ang next line kay di mag match
            else{
                fclose(fOpen);
                SetConsoleTextAttribute(hConsole, 12);
                printf("\n                                       Incorrect password");
                SetConsoleTextAttribute(hConsole, 11);
                getch();
                system("cls");
                fflush(stdin);
                return 0;
            }

        }
        else if( strcmp(recentLine, accCheck) == 0 ){
        char recRepLine[50];
        char repAccChck[50];
        int accCheckLenght = strlen( accCheck );

        accCheck[accCheckLenght+1] = '\n';

        firstRepeat = false;

        while( !firstRepeat ){
            fgets(repAccChck, 50, fOpen );

            if( strcmp(repAccChck, accCheck) == 0 ){
                firstRepeat = true;
                isEmpty = true;
            }
            else if( strcmp(recRepLine, repAccChck) == 0 ){
                firstRepeat = true;
                isEmpty = true;
            }
            else{
                firstRepeat = true;
            }

            strcpy(recRepLine, repAccChck);
        }
        }
        strcpy(recentLine, accCheck);
    }

    /// kung sa while loop sa ibabaw walay mag match na email or username
    fclose(fOpen);
    SetConsoleTextAttribute(hConsole, 12);
    printf("\n                                       Username not found");
    SetConsoleTextAttribute(hConsole, 11);
    getch();
    system("cls");
    fflush(stdin);
    return 0;
}


/// Registration function
void Register(){
    HANDLE hConsole;hConsole=GetStdHandle
    (STD_OUTPUT_HANDLE);

    bool checking;
    bool trueFalse = false;
    bool passMatch;
    bool isEmpty = false;
    char recentLine[50];
    char confirmPass[50];
    char emailChecker[50];
    char usernameChecker[50];


    /// nested while loop

    while(!trueFalse){
    checking = false;
    passMatch = false;

    printf("\n\n\n\n                                        ____  ____  ___  __  __  _  _  ____ ");
    printf("\n                                        ||__   ||  // __ ||\\\ ||  || || ||_||");
    printf("\n                                        ___|| _||_ \\\\_\\\\ || \\\||  ||_|| ||   ");
    printf("\n                                        ------------------------------------");


    fflush(stdin);
    printf("\n\n\n\n                                       Enter full name: ");
    fgets(nameReg, 50, stdin);
    fflush(stdin);
    printf("\n                                       Desired Username: ");
    fgets(usernameReg, 50, stdin);
    fflush(stdin);
    printf("\n                                       Email: ");
    fgets(emailReg, 50, stdin);
    fflush(stdin);
    printf("\n                                       Password recovery question: ");
    fgets(RecovQuestion, 500, stdin);
    fflush(stdin);
    printf("\n                                       Answer: ");
    fgets(Answer, 100, stdin);
    fflush(stdin);
    printf("\n                                       Credit card number: ");
    fgets( ccNumReg, 50, stdin );

    /// another while loop in case na invalid or di mag match ang ge create na password
    while(!passMatch){

    checking = false;

    fflush(stdin);
    printf("\n                                       create password: ");
    fgets(passwordReg, 50, stdin);
    fflush(stdin);
    printf("\n                                       confirm password: ");
    fgets(confirmPass, 50, stdin);
    fflush(stdin);

    if( strcmp(passwordReg, confirmPass) != 0){
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        printf("\n\n\n\n                                       Password does not match");
        SetConsoleTextAttribute(hConsole, 11);
        getch();
        system("cls");
        printf("\n\n\n\n                                        ____  ____  ___  __  __  _  _  ____ ");
        printf("\n                                        ||__   ||  // __ ||\\\ ||  || || ||_||");
        printf("\n                                        ___|| _||_ \\\\_\\\\ || \\\||  ||_|| ||   ");
        printf("\n                                        ------------------------------------\n\n\n");
        fflush(stdin);
        checking = true;
    }
    else if( strlen(passwordReg) < 9 ){
        system("cls");
        SetConsoleTextAttribute(hConsole, 12);
        printf("\n\n\n\n                                       Password must be 8 characters or longer");
        SetConsoleTextAttribute(hConsole, 11);
        getch();
        system("cls");
        printf("\n\n\n\n                                        ____  ____  ___  __  __  _  _  ____ ");
        printf("\n                                        ||__   ||  // __ ||\\\ ||  || || ||_||");
        printf("\n                                        ___|| _||_ \\\\_\\\\ || \\\||  ||_|| ||   ");
        printf("\n                                        ------------------------------------\n\n\n");
        fflush(stdin);
        checking = true;
    }
    else{

        /// Checking if the email is available using for loop

        FILE* fEmails = fopen("registeredAcc.dat", "r");

        while(!isEmpty){
            fgets(emailChecker, 50, fEmails);
            if( strcmp(emailReg, emailChecker)== 0 ){
                system("cls");
                SetConsoleTextAttribute(hConsole, 12);
                printf("\n\n\n\n                                       Email is already used from another account");
                SetConsoleTextAttribute(hConsole, 11);
                getch();
                passMatch = true;
                checking = true;
                isEmpty = true;
                fflush(stdin);
                system("cls");
                }
            else if( strcmp( recentLine, emailChecker )==0 ){ isEmpty = true; }

            strcpy(recentLine, emailChecker);
            }

            fclose(fEmails);

        /// Checking if the username is available

        FILE* fusername = fopen("registeredAcc.dat", "r");
        isEmpty = false;

        while(!isEmpty){
            fgets(usernameChecker, 50, fusername);
            if( strcmp(usernameReg, usernameChecker)== 0 ){
                system("cls");
                SetConsoleTextAttribute(hConsole, 12);
                printf("\n\n\n\n                                       Username is already used from another account");
                SetConsoleTextAttribute(hConsole, 11);
                getch();
                passMatch = true;
                checking = true;
                isEmpty = true;
                fflush(stdin);
                system("cls");
                }
            else if( strcmp( recentLine, usernameChecker )==0 ){ isEmpty = true; }

            strcpy(recentLine, usernameChecker);
            }

            fclose(fusername);


        }


        /// If okay ang tanan nga ge input kini moy mag pa hunong sa duha ka loop, passmatch ug truefalse na loop
        if(!checking){
        passMatch = true;
        trueFalse = true;
        }
    }

    }

    /// Storing the username, password, and email at registeredAcc.txt file

    FILE* fRegistered = fopen("registeredAcc.dat", "a");

    fprintf(fRegistered, "%s%s%s%s%s%s%s", usernameReg, passwordReg, emailReg, nameReg, ccNumReg, RecovQuestion, Answer);

    fclose(fRegistered);

    system("cls");

    SetConsoleTextAttribute(hConsole, 10);
    printf("\n\n\n\n                                       You Have successfully registered\n");
    printf("                                       Please proceed to login\n");
    SetConsoleTextAttribute(hConsole, 11);
    getch();
    fflush(stdin);
    system("cls");
}


int main()
{
    HANDLE hConsole;hConsole=GetStdHandle
    (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    char response[100];
    bool trueFalse = false;


    /// Simple switch case statement
    /// naay while loop kay incase mag pataka ug input ang user
    while(!trueFalse){

    balance = 0;

    printf("\n\n\n\n                                  _      _ ___   _     ____   ___  _    __ ____");
    printf("\n                                  \\\\    // |__  ||    //     // \\\\ ||\\\//|| ||__");
    printf("\n                                   \\\\/\\//  |__  ||___ \\\\___  \\\\_// ||   || ||__");
    printf("\n                                   --------------------------------------------");
    printf("\n\n                                       Hello what would like want to do?\n");
    printf("\n\n                                             [1] Login\n");
    printf("                                             [2] Register\n");
    printf("                                             [3] Forgot Password\n");
    printf("                                             [4] exit\n\n\n\n\n");
    printf("                                       Enter response: ");

    scanf("%s", response);

    if( response[0] == '1' ){
        system("cls");
        fflush(stdin);
        Login();
    }
    else if( response[0] == '2' ){
        system("cls");
        fflush(stdin);
        Register();
    }
    else if( response[0] == '3' ){
        system("cls");
        fflush(stdin);
        forgetPassword();
    }
    else if( response[0] == '4' ){
        system("cls");
        return 0;
    }

    else{
        fflush(stdin);
        SetConsoleTextAttribute(hConsole, 12);
        printf("\n                                       Invalid response!!");
        SetConsoleTextAttribute(hConsole, 11);
        getch();
        fflush(stdin);
        system("cls");
    }
    }
}
