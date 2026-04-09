#include <iostream>
#include <string>
using namespace std;

struct Patient
{
    string patient_name;
    int patient_age;
    string patient_gender;
    string patient_username;
    int patient_password;
    int patient_id; // ضفت ده عشان دالة الـ ID تشتغل
};

struct LabTest
{
    int testID;
    string testName;
    string category;
    int normalMinValue;
    int normalMaxvalue;
    int unit;
};

struct TestRequest
{
    int RequestID;
    int PatientID;
    int TestID;
    int RequestDate;
    int ResultValue;
    string status;
    bool isAbnormal;
};

struct LabTechnician
{
    int TechnicianID;
    int technicianPassword;
    string technician_Name;
    string technician_UserName;
    int CompletedTestsCount;
};

struct Admin
{
    int AdminID;
    int Admin_password;
    string Admin_username;
};

// المصفوفات والعدادات
Patient Patients[50];
int pCount = 0;

LabTest labtests[50];
int labTestCount = 0;

TestRequest TestRequests[100];
int testrequestsCount = 0;

LabTechnician LabTechnicians[20];
int labtechnicianCount = 0;

Admin admins[10];
int adminCount = 0;

void predefinePatients() {
    Patients[0].patient_name = "Saif Elwan";
    Patients[0].patient_username = "saif1";
    Patients[0].patient_password = 111;
    Patients[0].patient_age = 19;
    Patients[0].patient_gender = "male";
    Patients[0].patient_id = 101;

    Patients[1].patient_name = "Saif Wahdan"; 
    Patients[1].patient_username = "saif2";
    Patients[1].patient_password = 222;
    Patients[1].patient_age = 20;
    Patients[1].patient_gender = "male";
    Patients[1].patient_id = 102;

    pCount = 2; 
}
// دوال تبعي تبدا من هنا 
// دالة Duplicate للمريض (Username)
bool isDuplicatePatient(string dublicate_username)
{
    for(int i = 0; i < pCount; i++)
    {
        if (dublicate_username == Patients[i].patient_username) // تصحيح حرف P
        {
            return true;
        }
    }
    return false; // تصحيح مكان الـ return
}

// دالة Duplicate للمريض (ID)
bool isDuplicatePatient(int dublicate_id)
{
    for(int i = 0; i < pCount; i++)
    {
        if (dublicate_id == Patients[i].patient_id) 
        {
            return true;
        }
    }
    return false;
}

// دالة Duplicate للفني (Username)
bool isDuplicatetechnician(string dublicate_username)
{
    for(int i = 0; i < labtechnicianCount; i++)
    {
        if (dublicate_username == LabTechnicians[i].technician_UserName)
        {
            return true;
        }
    }
    return false;
}

// دالة Duplicate للفني (ID)
bool isDuplicatetechnician(int dublicate_id)
{
    for(int i = 0; i < labtechnicianCount; i++)
    {
        if (dublicate_id == LabTechnicians[i].TechnicianID) // تصحيح المقارنة بـ ID مش UserName
        {
            return true;
        }
    }
    return false;
}
// function is check duplicate(labtest ) use  (ID)
bool isDuplicatelabtest(int dublicate_id)
{
  for(int i=0;i<labTestCount;i++)
     {
      if (dublicate_id==labtests[i].testID)
         {
          return true;
         }
     }
     return false;
}
bool isDuplicaterequest (int dublicatepatient_id,int dublicatelabtest_id,int RequestDate)
  {
    for(int i=0;i<testrequestsCount;i++)
      {
        if (dublicatepatient_id==TestRequests[i].PatientID&&
          dublicatelabtest_id==TestRequests[i].TestID&&RequestDate==TestRequests[i].RequestDate)
           {
            return true;
           }
      }
      return false;
  }
  // return index of patient 
  int findPatientByUsername(string username_patient)
  {
    
    for(int i=0;i<pCount;i++)
      {
        if (username_patient==Patients[i].patient_username)
          {
            return i;
          }
      }
      return -1 ;
  }
  // return index of Technicians 
    int findTechnicianByUsername(string username_Technicians)
  {
    
    for(int i=0;i<labtechnicianCount;i++)
      {
        if (username_Technicians==LabTechnicians[i].technician_UserName)
          {
            return i;
          }
      }
      return -1 ;
  }
    // return index of labtest use (ID) 
      int findlabtestbyid(int labtest_id)
  {
    
    for(int i=0;i<labTestCount;i++)
      {
        if (labtest_id==labtests[i].testID)
          {
            return i;
          }
      }
      return -1 ;
  }
  // return index of request use (ID)
  int findrequestbyid(int request_id)
    {
    
    for(int i=0;i<testrequestsCount;i++)
      {
        if (request_id==TestRequests[i].RequestID)
          {
            return i;
          }
      }
      return -1 ;
  }
  // function check be Abnarmal
  bool isResultAbnormal(int test_id ,int Degree_test)
  {
    int index =findlabtestbyid(test_id);
    
    if (index>=0)
    {
      if (labtests[index].normalMinValue>Degree_test||labtests[index].normalMaxvalue<Degree_test)
         {
          return true;
         }
    }
    return false;
  }
  // set up counter  id to (patient,request,Technicians,labtest) note this counter increment only 
 long long  counteridpatient=100;
 long long  counteridTechnician=1000;
 long long  counteridlabtest=10000;
 long long  counteridrequest=20000;
  //function generate patient id
  
int generatepatientid()
{
  int newid1=counteridpatient;
  counteridpatient++;
  return newid1;
}
  //function generate labtest id
int generatelabtestid()
{
  int newid2=counteridlabtest;
  counteridlabtest++;
  return newid2;
}
  //function generate Technician id
int generatecounteridTechnicianid()
{
  int newid3=counteridTechnician;
  counteridTechnician++;
  return newid3;
}
  //function generate request id
int generaterequestid()
{
  int newid4= counteridrequest;
  counteridrequest++;
  return newid4;
}
int main()
{
    predefinePatients();
    
    return 0;
}