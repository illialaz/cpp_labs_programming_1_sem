#include <iostream>
using namespace std;

int main(void){
  int num, month, year;
  cout<<"Enter a date"<<endl;
  cin>>num>>month>>year;
  if (year % 4 == 0 && year % 100 != 0){
    if (month == 2){
      if (num == 29){
        month ++;
        num = 1;
      } else if (num > 29){
        cout<<"Incorrect date"<<endl;
        return 0;
      }else {
        num ++;
      }
      cout<<num<<"."<<month<<"."<<year;
      return 0;
    }
  } 
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10){
    if (num == 31){
      month ++;
      num = 1;
    } else if (num > 31){
      cout<<"Incorrect date"<<endl;
      return 0;
    }else {
      num ++;
    }
    cout<<num<<"."<<month<<"."<<year;
    return 0;
  }
  if (month == 2){
    if (num == 28){
        month ++;
        num = 1;
    } else if (num > 28){
        cout<<"Incorrect date"<<endl;
        return 0;
      }else {
        num ++;
    }
    cout<<"Next day date is: "<<num<<"."<<month<<"."<<year;
    return 0;
  } else if (month == 4 || month == 6 || month == 9 || month == 11){
    if (num == 30){
      month ++;
       num = 1;
     } else if (num > 30){
      cout<<"Incorrect date"<<endl;
       return 0;
     } else {
       num ++;
     }
     cout<<num<<"."<<month<<"."<<year;
    return 0;
  } else if (month == 12){
    if (num == 31){
      month = 1;
      num = 1;
      year++;
    } else if (num > 31){
      cout<<"Incorrect date"<<endl;
      return 0;
    } else {
      num ++;
    }
    cout<<num<<"."<<month<<"."<<year;
    return 0;
  } else {
    cout<<"Incorrect date"<<endl;
  }
 return 0;
}
