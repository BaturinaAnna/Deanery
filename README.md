# Deanery

### Class **Student** to store information about student

Fields:

- **id** - identificator of student
- **fio** - surname and initials
- **group** - reference to the group (Group object)
- **marks** - vector of marks

Methods:

- create a student with ID and full name 
- set a group to the student
- add a mark
- count average mark for a student
- get full name
- get marks 
- get id
- get group

### Class **Group** to store information about study group

Fields:

- **title** - group name
- **spec** - speciality
- **students** - vector of references to students
- **head** - reference to the head of group (person from group membors)

Methods:

- create a group with group name and speciality
- add a student
- elect the head of group
- find student by full name or by id
- count average mark in a group
- student expulsion
- get references to all students in a group
- get title of the group
- get reference to the head of the group
- get speciality of the group

### Class **Deanery**

Fields:

- **groups** - references to all groups

Methods:

- create students based on data from a file
- create groups based on data from a file 
- add random marks to students
- get statistics on the progress of students and groups 
- transfer of students from group to group
- expulsion of students for academic failure
- save updated data in files
- initiation of election of headmen in groups 
- output data to the console 