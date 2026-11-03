// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData{
    struct student{
        string name;
        uint id;
    }

    student[] public students;

    function addStudent(string memory name, uint id) public {
        for(uint i = 0; i<students.length; i++)
        {
            if(students[i].id == id){
                revert("This student already exists!");
            }
        }

        students.push(student(name, id));
    }

    function NumberOfStudents() public view returns(uint) {
        return students.length;
    }

    function DisplayStudent(uint id) public view returns(student memory) {
        for(uint i = 0; i<students.length; i++)
        {
            if(students[i].id == id){
                return(students[i]);
            }
        }

        revert("Student does not exist!!");
    }

    fallback() external payable {
        // Handles calls to undefined functions
    }

    receive() external payable {
        // Handles Ether sent without data
    }
}