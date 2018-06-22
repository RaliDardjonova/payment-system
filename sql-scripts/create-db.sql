CREATE DATABASE PaymentSystem;
USE PaymentSystem;

CREATE TABLE PaymentOrder
(
  order_id VARCHAR(50) NOT NULL,
  type CHAR(1) NOT NULL,
  PRIMARY KEY (order_id)
);

CREATE TABLE OrdinaryOrder
(
  order_id VARCHAR(50) NOT NULL,
  receiverIBAN CHAR(22) NOT NULL,
  receiverName VARCHAR(200) NOT NULL,
  amount FLOAT NOT NULL,
  description VARCHAR(200) NOT NULL,
  paymentSystem CHAR(1) NOT NULL,
  PRIMARY KEY (order_id),
  FOREIGN KEY (order_id) REFERENCES PaymentOrder(order_id)
);

CREATE TABLE InternationalBank
(
  bankSWIFT CHAR(8) NOT NULL,
  bankName VARCHAR(200) NOT NULL,
  bankAddress VARCHAR(200) NOT NULL,
  PRIMARY KEY (bankSWIFT)
);

CREATE TABLE Document
(
  documentNumber VARCHAR(50) NOT NULL,
  documentType CHAR(1) NOT NULL,
  documentDate DATE NOT NULL,
  debitedParty VARCHAR(200) NOT NULL,
  PRIMARY KEY (documentNumber)
);

CREATE TABLE InternationalOrder
(
  order_id VARCHAR(50) NOT NULL,
  receiverIBAN CHAR(22) NOT NULL,
  receiverName VARCHAR(200) NOT NULL,
  currency CHAR(3) NOT NULL,
  amount FLOAT NOT NULL,
  description VARCHAR(200) NOT NULL,
  receiverAddress VARCHAR(200) NOT NULL,
  receiverCountry VARCHAR(50) NOT NULL,
  operationCode CHAR(3) NOT NULL,
  executionPeriod CHAR(1) NOT NULL,
  senderCharges CHAR(1) NOT NULL,
  receiverCharges CHAR(1) NOT NULL,
  receiverBankSWIFT CHAR(8) NOT NULL,
  otherBankSWIFT CHAR(8) ,
  PRIMARY KEY (order_id),
  FOREIGN KEY (order_id) REFERENCES PaymentOrder(order_id),
  FOREIGN KEY (receiverBankSWIFT) REFERENCES InternationalBank(bankSWIFT),
  FOREIGN KEY (otherBankSWIFT) REFERENCES InternationalBank(bankSWIFT)
);

CREATE TABLE ToBudgetOrder
(
  order_id VARCHAR(50) NOT NULL,
  receiverIBAN CHAR(22) NOT NULL,
  receiverName VARCHAR(200) NOT NULL,
  amount FLOAT NOT NULL,
  description VARCHAR(200) NOT NULL,
  relevantPaymentStartDate DATE NOT NULL,
  relevantPaymentEndDate DATE NOT NULL,
  paymentType CHAR(6) NOT NULL,
  paymentSystem CHAR(1) NOT NULL,
  documentNumber VARCHAR(50) NOT NULL,
  PRIMARY KEY (order_id),
  FOREIGN KEY (order_id) REFERENCES PaymentOrder(order_id),
  FOREIGN KEY (documentNumber) REFERENCES Document(documentNumber)
);

CREATE TABLE Bank
(
  BIC CHAR(8) NOT NULL,
  name VARCHAR(200) NOT NULL,
  shortName CHAR(4) NOT NULL,
  PRIMARY KEY (BIC)
);
