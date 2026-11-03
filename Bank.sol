// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank{
    uint256 balance = 0;
    address public accOwner;        

    constructor(){
        accOwner = msg.sender;
    }

    function Deposite() public payable  {
        require(accOwner == msg.sender, "You are the owner of account");
        require(msg.value > 0 , "Amount should be greater than 0!!");
        balance += msg.value;
    }

    function Credit() public payable  {
        require(accOwner == msg.sender, "You are the owner of account");
        require(msg.value > 0 , "Amount should be greater than 0!");
        balance -= msg.value;
    }

    function showBalance() public view returns (uint256) {
        require(accOwner == msg.sender, "You are the owner of account");
        return balance;
    }
}