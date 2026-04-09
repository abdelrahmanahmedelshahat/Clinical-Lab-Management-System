#include <iostream>
#include <string>
using namespace std;

// --- CONSTANTS ---
const int MAX_PATIENTS = 50;
const int MAX_LAB_TESTS = 50;
const int MAX_REQUESTS = 100;
const int MAX_TECHNICIANS = 20;
const int MAX_ADMINS = 10;

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
    int test_id;
    string test_name;
    string category;
    int normal_min_value;
    int normal_max_value;
    int unit;
};

struct TestRequest
{
    int request_id;
    int patient_id;
    int test_id;
    int request_date;
    int result_value;
    string status;
    bool is_abnormal;
};

struct LabTechnician
{
    int technician_id;
    int technician_password;
    string technician_name;
    string technician_user_name;
    int completed_tests_count;
};

struct Admin
{
    int admin_id;
    int admin_password;
    string admin_username;
};

// المصفوفات والعدادات
Patient patients[MAX_PATIENTS];
int p_count = 0;

LabTest lab_tests[MAX_LAB_TESTS];
int lab_test_count = 0;

TestRequest test_requests[MAX_REQUESTS];
int test_requests_count = 0;

LabTechnician lab_technicians[MAX_TECHNICIANS];
int lab_technician_count = 0;

Admin admins[MAX_ADMINS];
int admin_count = 0;

void predefinePatients() {
    patients[0].patient_name = "Saif Elwan";
    patients[0].patient_username = "saif1";
    patients[0].patient_password = 111;
    patients[0].patient_age = 19;
    patients[0].patient_gender = "male";
    patients[0].patient_id = 101;

    patients[1].patient_name = "Saif Wahdan"; 
    patients[1].patient_username = "saif2";
    patients[1].patient_password = 222;
    patients[1].patient_age = 20;
    patients[1].patient_gender = "male";
    patients[1].patient_id = 102;

    p_count = 2; 
}
// دوال تبعي تبدا من هنا 
// دالة Duplicate للمريض (Username)
bool isDuplicatePatient(string dublicate_username)
{
    for(int i = 0; i < p_count; i++)
    {
        if (dublicate_username == patients[i].patient_username) // تصحيح حرف P
        {
            return true;
        }
    }
    return false; // تصحيح مكان الـ return
}

// دالة Duplicate للمريض (ID)
bool isDuplicatePatientById(int dublicate_id)
{
    for(int i = 0; i < p_count; i++)
    {
        if (dublicate_id == patients[i].patient_id) 
        {
            return true;
        }
    }
    return false;
}

// دالة Duplicate للفني (Username)
bool isDuplicateTechnician(string dublicate_username)
{
    for(int i = 0; i < lab_technician_count; i++)
    {
        if (dublicate_username == lab_technicians[i].technician_user_name)
        {
            return true;
        }
    }
    return false;
}

// دالة Duplicate للفني (ID)
bool isDuplicateTechnicianById(int dublicate_id)
{
    for(int i = 0; i < lab_technician_count; i++)
    {
        if (dublicate_id == lab_technicians[i].technician_id) // تصحيح المقارنة بـ ID مش UserName
        {
            return true;
        }
    }
    return false;
}
// function is check duplicate(labtest ) use  (ID)
bool isDuplicateLabTest(int dublicate_id)
{
  for(int i=0;i<lab_test_count;i++)
     {
      if (dublicate_id==lab_tests[i].test_id)
         {
          return true;
         }
     }
     return false;
}
bool isDuplicateRequest(int dublicate_patient_id,int dublicate_labtest_id,int request_date)
  {
    for(int i=0;i<test_requests_count;i++)
      {
        if (dublicate_patient_id==test_requests[i].patient_id&&
          dublicate_labtest_id==test_requests[i].test_id&&request_date==test_requests[i].request_date)
           {
            return true;
           }
      }
      return false;
  }
  // return index of patient 
  int findPatientByUsername(string username_patient)
  {
    
    for(int i=0;i<p_count;i++)
      {
        if (username_patient==patients[i].patient_username)
          {
            return i;
          }
      }
      return -1 ;
  }
  // return index of Technicians 
    int findTechnicianByUsername(string username_technicians)
  {
    
    for(int i=0;i<lab_technician_count;i++)
      {
        if (username_technicians==lab_technicians[i].technician_user_name)
          {
            return i;
          }
      }
      return -1 ;
  }
    // return index of labtest use (ID) 
      int findLabTestById(int labtest_id)
  {
    
    for(int i=0;i<lab_test_count;i++)
      {
        if (labtest_id==lab_tests[i].test_id)
          {
            return i;
          }
      }
      return -1 ;
  }
  // return index of request use (ID)
  int findRequestById(int request_id)
    {
    
    for(int i=0;i<test_requests_count;i++)
      {
        if (request_id==test_requests[i].request_id)
          {
            return i;
          }
      }
      return -1 ;
  }
  // function check be Abnarmal
  bool isResultAbnormal(int test_id ,int degree_test)
  {
    int index =findLabTestById(test_id);
    
    if (index>=0)
    {
      if (lab_tests[index].normal_min_value>degree_test||lab_tests[index].normal_max_value<degree_test)
         {
          return true;
         }
    }
    return false;
  }
  // set up counter  id to (patient,request,Technicians,labtest) note this counter increment only 
long long  counter_id_patient=100;
long long  counter_id_technician=1000;
long long  counter_id_labtest=10000;
long long  counter_id_request=20000;
  //function generate patient id
  
int generatePatientId()
{
  int new_id1=counter_id_patient;
  counter_id_patient++;
  return new_id1;
}
  //function generate labtest id
int generateLabTestId()
{
  int new_id2=counter_id_labtest;
  counter_id_labtest++;
  return new_id2;
}
  //function generate Technician id
int generateTechnicianId()
{
  int new_id3=counter_id_technician;
  counter_id_technician++;
  return new_id3;
}
  //function generate request id
int generateRequestId()
{
  int new_id4= counter_id_request;
  counter_id_request++;
  return new_id4;
}
int main()
{
    predefinePatients();
    
    return 0;
}
