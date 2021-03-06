CREATE TABLE USER_LOG ( 
User_ID SMALLINT NOT NULL,
User_Type_ID SMALLINT NOT NULL,
Login_ID VARCHAR(30) NOT NULL,
Login_Password VARCHAR(20) NOT NULL,
First_Name VARCHAR(30) NOT NULL,
Last_Name VARCHAR(30) NOT NULL,
Phone_Number VARCHAR(10) NOT NULL,
Email VARCHAR(30) NOT NULL);

CREATE TABLE USER_TYPE (
User_Type_ID SMALLINT NOT NULL,
User_Description VARCHAR(50) NOT NULL);

CREATE TABLE APPLICANT (
Applicant_ID SMALLINT NOT NULL,
User_ID SMALLINT NOT NULL,
Program_ID SMALLINT NOT NULL,
Status_ID SMALLINT NOT NULL);

CREATE TABLE APPLICATION (
Application_ID SMALLINT NOT NULL,
Applicant_ID SMALLINT NOT NULL,
Application_Year SMALLINT NOT NULL,
Year_In_School VARCHAR(10) NOT NULL,
Grad_Date DATE NOT NULL,
Student_ID VARCHAR(9) NOT NULL,
Why_this_program VARCHAR(150) NOT NULL,
ETC VARCHAR(50) NOT NULL);

CREATE TABLE STATUS (
Status_ID SMALLINT NOT NULL,
Status_Description VARCHAR(50) NOT NULL);

CREATE TABLE ADVISOR (
Advisor_ID SMALLINT NOT NULL,
User_ID SMALLINT NOT NULL,
Program_ID SMALLINT NOT NULL);

CREATE TABLE COMPANY_REP (
Rep_ID SMALLINT NOT NULL,
User_ID SMALLINT NOT NULL,
Company_ID SMALLINT NOT NULL,
Cell_Phone VARCHAR(10) NULL);

CREATE TABLE COMPANY (
Company_ID SMALLINT NOT NULL,
Company_Name VARCHAR(30) NOT NULL,
Address VARCHAR(50) NOT NULL,
Phone VARCHAR(10) NOT NULL); 

CREATE TABLE COLLEGE (
College_ID SMALLINT NOT NULL,
University VARCHAR(30) NOT NULL,
College VARCHAR(30) NOT NULL);

CREATE TABLE PROGRAM (
Program_ID SMALLINT NOT NULL,
College_ID SMALLINT NOT NULL,
Major_ID SMALLINT NOT NULL);

CREATE TABLE MAJOR (
Major_ID SMALLINT NOT NULL,
Major_Description VARCHAR(30) NOT NULL);

CREATE TABLE PRESCREEN (
Prescreen_ID SMALLINT NOT NULL,
Applicant_ID SMALLINT NOT NULL,
Program_ID SMALLINT NOT NULL,
GPA SMALLINT NOT NULL,
GPA_Trent VARCHAR(20) NOT NULL,
GPA_Explanation VARCHAR(50) NOT NULL,
Pro_School_Likelihood VARCHAR(20) NOT NULL,
PSL_Response VARCHAR(50) NOT NULL,
Pre_Req_Likelihood VARCHAR(20) NOT NULL,
PRL_Response VARCHAR(50) NOT NULL,
Signature VARCHAR(20) NOT NULL,
Status VARCHAR(20) NOT NULL,
Prescreen_Comments VARCHAR(150) NULL);

CREATE TABLE EVENT_LOG (
Log_ID SMALLINT NOT NULL,
User_ID SMALLINT NOT NULL,
Date_time DATE NOT NULL,
Application_ID SMALLINT NOT NULL,
Previous_Status VARCHAR(150) NOT NULL,
Current_Status VARCHAR(150) NOT NULL,
Log_Comments VARCHAR (150) NOT NULL);

CREATE TABLE INTERVIEW (
Interview_ID SMALLINT NOT NULL,
Interview_Date DATE NOT NULL,
Location VARCHAR(30) NOT NULL,
Major_ID SMALLINT NOT NULL);

CREATE TABLE INTERVIEW_STAFF (
Interview_Staff_ID SMALLINT NOT NULL,
Interview_ID SMALLINT NOT NULL,
User_ID SMALLINT NOT NULL);

CREATE TABLE STUDENT_INTERVIEW (
Student_Interview_ID SMALLINT NOT NULL,
Applicant_ID SMALLINT NOT NULL,
Interview_ID SMALLINT NOT NULL,
Interivew_Time DATETIME NOT NULL,
Interview_Score SMALLINT NULL,
Interview_Result_Type_ID SMALLINT NULL);

CREATE TABLE INTERVIEW_RESULT_TYPE (
Interview_Result_Type_ID SMALLINT NOT NULL,
Result_Type_Description VARCHAR(50) NOT NULL);

ALTER TABLE USER_LOG ADD CONSTRAINT pk_USER_LOG PRIMARY KEY (User_ID);

ALTER TABLE USER_TYPE ADD CONSTRAINT pk_USER_TYPE PRIMARY KEY (User_Type_ID);

ALTER TABLE APPLICANT ADD CONSTRAINT pk_APPLICANT PRIMARY KEY (Applicant_ID);

ALTER TABLE APPLICATION ADD CONSTRAINT pk_APPLICATION PRIMARY KEY (Application_ID);

ALTER TABLE STATUS ADD CONSTRAINT pk_STATUS PRIMARY KEY (Status_ID);

ALTER TABLE ADVISOR ADD CONSTRAINT pk_ADVISOR PRIMARY KEY (Advisor_ID);

ALTER TABLE COMPANY_REP ADD CONSTRAINT pk_COMPANY_REP PRIMARY KEY (Rep_ID);

ALTER TABLE COMPANY ADD CONSTRAINT pk_COMPANY PRIMARY KEY (Company_ID);

ALTER TABLE COLLEGE ADD CONSTRAINT pk_COLLEGE PRIMARY KEY (College_ID);

ALTER TABLE PROGRAM ADD CONSTRAINT pk_PROGRAM PRIMARY KEY (Program_ID);

ALTER TABLE MAJOR ADD CONSTRAINT pk_MAJOR PRIMARY KEY (Major_ID);

ALTER TABLE PRESCREEN ADD CONSTRAINT pk_PRESCREEN PRIMARY KEY (Prescreen_ID);

ALTER TABLE EVENT_LOG ADD CONSTRAINT pk_LOG PRIMARY KEY (Log_ID);

ALTER TABLE INTERVIEW ADD CONSTRAINT pk_INTERVIEW PRIMARY KEY (Interview_ID);

ALTER TABLE INTERVIEW_STAFF ADD CONSTRAINT pk_INTERVIEW_STAFF PRIMARY KEY (Interview_Staff_ID);

ALTER TABLE STUDENT_INTERVIEW ADD CONSTRAINT pk_STUDENT_INTERVIEW PRIMARY KEY (Student_Interview_ID);

ALTER TABLE INTERVIEW_RESULT_TYPE ADD CONSTRAINT pk_INTERVIEW_RESULT_TYPE PRIMARY KEY (Interview_Result_Type_ID);

ALTER TABLE USER_LOG ADD CONSTRAINT fk_USER_LOG FOREIGN KEY (User_Type_ID)
REFERENCES USER_TYPE (User_Type_ID);

ALTER TABLE APPLICANT ADD CONSTRAINT fk1_APPLICANT FOREIGN KEY (User_ID)
REFERENCES USER_LOG (User_ID);

ALTER TABLE APPLICANT ADD CONSTRAINT fk2_APPLICANT FOREIGN KEY (Program_ID)
REFERENCES PROGRAM (Program_ID);

ALTER TABLE APPLICANT ADD CONSTRAINT fk3_APPLICANT FOREIGN KEY (Status_ID)
REFERENCES STATUS (Status_ID);

ALTER TABLE APPLICATION ADD CONSTRAINT fk_APPLICATION FOREIGN KEY (Applicant_ID)
REFERENCES APPLICANT (Applicant_ID);

ALTER TABLE ADVISOR ADD CONSTRAINT fk1_ADVISOR FOREIGN KEY (User_ID)
REFERENCES USER_LOG (User_ID);

ALTER TABLE ADVISOR ADD CONSTRAINT fk2_ADVISOR FOREIGN KEY (Program_ID)
REFERENCES PROGRAM (Program_ID);

ALTER TABLE COMPANY_REP ADD CONSTRAINT fk1_COMPANY_REP FOREIGN KEY (User_ID)
REFERENCES USER_LOG (User_ID);

ALTER TABLE COMPANY_REP ADD CONSTRAINT fk2_COMPANY_REP FOREIGN KEY (Company_ID)
REFERENCES COMPANY (Company_ID);

ALTER TABLE PROGRAM  ADD CONSTRAINT fk1_PROGRAM FOREIGN KEY (College_ID)
REFERENCEs COLLEGE (College_ID);

ALTER TABLE PROGRAM ADD CONSTRAINT fk2_PROGRAM FOREIGN KEY (Major_ID)
REFERENCES MAJOR (Major_ID);

ALTER TABLE PRESCREEN ADD CONSTRAINT fk1_PRESCREEN FOREIGN KEY (Applicant_ID)
REFERENCES APPLICANT (Applicant_ID);

ALTER TABLE PRESCREEN ADD CONSTRAINT fk2_PRESCREEN FOREIGN KEY (Program_ID)
REFERENCES PROGRAM (Program_ID);

ALTER TABLE EVENT_LOG ADD CONSTRAINT fk1_LOG FOREIGN KEY (User_ID)
REFERENCES USER_LOG (User_ID);

ALTER TABLE EVENT_LOG ADD CONSTRAINT fk2_LOG FOREIGN KEY (Application_ID)
REFERENCES APPLICATION (Application_ID);

ALTER TABLE INTERVIEW ADD CONSTRAINT fk_INTERVIEW FOREIGN KEY (Major_ID)
REFERENCES MAJOR (Major_ID);

ALTER TABLE INTERVIEW_STAFF ADD CONSTRAINT fk1_INTERVIEW_STAFF FOREIGN KEY (Interview_ID)
REFERENCES INTERVIEW (Interview_ID);

ALTER TABLE INTERVIEW_STAFF ADD CONSTRAINT fk2_INTERVIEW_STAFF FOREIGN KEY (User_ID)
REFERENCES USER_LOG (User_ID);

ALTER TABLE STUDENT_INTERVIEW ADD CONSTRAINT fk1_STUDENT_INTERVIEW FOREIGN KEY (Applicant_ID)
REFERENCES APPLICANT (Applicant_ID);

ALTER TABLE STUDENT_INTERVIEW ADD CONSTRAINT fk2_STUDENT_INTERVIEW FOREIGN KEY (Interview_ID)
REFERENCES INTERVIEW (Interview_ID);

ALTER TABLE STUDENT_INTERVIEW ADD CONSTRAINT fk3_STUDENT_INTERVIEW FOREIGN KEY (Interview_Result_Type_ID)
REFERENCES INTERVIEW_RESULT_TYPE (Interview_Result_Type_ID);
