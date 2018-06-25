CREATE DATABASE PaymentSystem;
USE PaymentSystem;

CREATE TABLE PaymentOrder
(
  order_id INT NOT NULL AUTO_INCREMENT,
  type CHAR(1) NOT NULL,
  isTemplate CHAR(1) NOT NULL,
  senderIBAN CHAR(22) NOT NULL,
  senderName VARCHAR(200) NOT NULL,
  PRIMARY KEY (order_id)
);

CREATE TABLE OrdinaryOrder
(
  order_id INT NOT NULL,
  receiverIBAN CHAR(22) NOT NULL,
  receiverName VARCHAR(200) NOT NULL,
  amount FLOAT NOT NULL,
  description VARCHAR(200) NOT NULL,
  settlementSystem CHAR(1) NOT NULL,
  PRIMARY KEY (order_id),
  FOREIGN KEY (order_id) REFERENCES PaymentOrder(order_id) ON DELETE CASCADE
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

CREATE TABLE Transaction
(
  trans_id INT NOT NULL AUTO_INCREMENT,
  order_id INT NOT NULL,
  signDate DATE NOT NULL,
  status CHAR(1) NOT NULL,
  PRIMARY KEY (trans_id),
  FOREIGN KEY (order_id) REFERENCES PaymentOrder(order_id) ON DELETE CASCADE
);

CREATE TABLE InternationalOrder
(
  order_id INT NOT NULL,
  receiverIBAN CHAR(22) NOT NULL,
  receiverName VARCHAR(200) NOT NULL,
  currency CHAR(3) NOT NULL,
  amount FLOAT NOT NULL,
  description VARCHAR(200) NOT NULL,
  receiverAddress VARCHAR(200) NOT NULL,
  receiverCountry VARCHAR(50) NOT NULL,
  executionPeriod CHAR(1) NOT NULL,
  senderCharges CHAR(1) NOT NULL,
  receiverCharges CHAR(1) NOT NULL,
  receiverBankSWIFT CHAR(8) NOT NULL,
  intermediaryBankSWIFT CHAR(8),
  PRIMARY KEY (order_id),
  FOREIGN KEY (order_id) REFERENCES PaymentOrder(order_id) ON DELETE CASCADE,
  FOREIGN KEY (receiverBankSWIFT) REFERENCES InternationalBank(bankSWIFT),
  FOREIGN KEY (intermediaryBankSWIFT) REFERENCES InternationalBank(bankSWIFT)
);

CREATE TABLE FromToBudgetOrder
(
  order_id INT NOT NULL,
  receiverIBAN CHAR(22) NOT NULL,
  receiverName VARCHAR(200) NOT NULL,
  amount FLOAT NOT NULL,
  description VARCHAR(200) NOT NULL,
  relevantPaymentStartDate DATE NOT NULL,
  relevantPaymentEndDate DATE NOT NULL,
  paymentType CHAR(6) NOT NULL,
  settlementSystem CHAR(1) NOT NULL,
  documentNumber VARCHAR(50) NOT NULL,
  PRIMARY KEY (order_id),
  FOREIGN KEY (order_id) REFERENCES PaymentOrder(order_id) ON DELETE CASCADE,
  FOREIGN KEY (documentNumber) REFERENCES Document(documentNumber)
);

CREATE TABLE Bank
(
  BIC CHAR(8) NOT NULL,
  name VARCHAR(200) NOT NULL,
  shortName CHAR(4) NOT NULL,
  PRIMARY KEY (BIC)
);

insert into Bank values ('RZBBBGSF', 'raifai', 'RZBB');
insert into InternationalBank values ( '12345678', 'nqkwa banka1', 'sofiq, adresa na nqkwata banka');
insert into InternationalBank values ('00000000', '', '');
insert into Document values ('123456', '9', '2012-12-23', 'Ivan Ivanov');
insert into Document values ('asd123', '1', '2018-12-31', 'Pesho Peshov');
