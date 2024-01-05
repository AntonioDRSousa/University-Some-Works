INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (0,'hotel 0','Descricao hotel 0',1,TRUE,1);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (1,'hotel 1','Descricao hotel 1',100,FALSE,3);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (2,'hotel 2','Descricao hotel 2',45,TRUE,10);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (3,'hotel 3','Descricao hotel 3',1,TRUE,2);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (4,'hotel 4','Descricao hotel 4',8,FALSE,2);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (5,'hotel 5','Descricao hotel 5',10,FALSE,1);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (6,'hotel 6','Descricao hotel 6',6,TRUE,6);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (7,'hotel 7','Descricao hotel 7',1000,FALSE,4);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (8,'hotel 8','Descricao hotel 8',50,TRUE,3);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (9,'hotel 9','Descricao hotel 9',12,FALSE,1);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (10,'hotel 10','Descricao hotel 10',15,TRUE,8);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (11,'hotel 11','Descricao hotel 11',25,FALSE,9);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (12,'hotel 12','Descricao hotel 12',500,TRUE,5);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (13,'hotel 13','Descricao hotel 13',10,FALSE,7);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (14,'hotel 14','Descricao hotel 14',3,TRUE,2);
INSERT INTO HOTEL (ID_HOTEL,NOME,DESCRICAO,DIS_PRAIA,PISCINA,ID_CIDADE) VALUES (15,'hotel 15','Descricao hotel 15',4,FALSE,6);

insert into cidades values(1,'Cabo Frio','RJ');
insert into cidades values(2,'Búzios','RJ');
insert into cidades values(3,'São Paulo','SP');
insert into cidades values(4,'Ouro Preto','MG');
insert into cidades values(5,'Belo Horizonte','MG');
insert into cidades values(6,'Fortaleza','CE');
insert into cidades values(7,'Porto Seguro','BA');
insert into cidades values(8,'Salvador','BA');
insert into cidades values(9,'Florianópolis','SC');
insert into cidades values(10,'Blumenau','SC');

insert into estados values('RJ','Rio de Janeiro');
insert into estados values('SP','São Paulo');
insert into estados values('MG','Minas Gerais');
insert into estados values('SC','Santa Catarina');
insert into estados values('CE','Ceará');
insert into estados values('BA','Bahia');

insert into possui values(1,'RJ');
insert into possui values(1,'SP');
insert into possui values(1,'BA');
insert into possui values(2,'MG');
insert into possui values(2,'SC');
insert into possui values(2,'CE');
insert into possui values(3,'RJ');
insert into possui values(3,'MG');
insert into possui values(3,'BA');
insert into possui values(3,'CE');

INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (0,'2021-05-01 12:00:00','2021-06-01 12:00:00',2,TRUE,FALSE,TRUE,1500.90,101,1,3);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (1,'2021-05-02 12:00:00','2021-06-02 12:00:00',4,FALSE,FALSE,FALSE,1109,87,102,2,2);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (2,'2021-05-03 12:00:00','2021-06-03 12:00:00',8,TRUE,FALSE,TRUE,2500.56,103,2,11);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (3,'2021-05-04 12:00:00','2021-06-04 12:00:00',16,FALSE,FALSE,TRUE,1945.23,104,1,1);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (4,'2021-05-05 12:00:00','2021-06-05 12:00:00',2,TRUE,FALSE,FALSE,1387.47,201,1,0);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (5,'2021-05-06 12:00:00','2021-06-06 12:00:00',3,FALSE,FALSE,TRUE,2106.79,202,2,15);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (6,'2021-05-07 12:00:00','2021-06-07 12:00:00',5,TRUE,FALSE,FALSE,1000.00,203,3,10);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (7,'2021-05-08 12:00:00','2021-06-08 12:00:00',7,FALSE,TRUE,2345.67,204,3,12);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (8,'2021-05-01 12:00:00','2021-06-01 12:00:00',11,TRUE,FALSE,FALSE,1234.56,301,3,14);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (9,'2021-05-02 12:00:00','2021-06-02 12:00:00',3,FALSE,FALSE,TRUE,967.99,302,3,13);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (10,'2021-05-03 12:00:00','2021-06-03 12:00:00',4,TRUE,FALSE,TRUE,3450.78,303,,1,10);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (11,'2021-05-04 12:00:00','2021-06-04 12:00:00',5,FALSE,TRUE,FALSE,1823.45,304,2,11);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (12,'2021-05-05 12:00:00','2021-06-05 12:00:00',6,TRUE,TRUE,TRUE,2000.00,401,1,9);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (13,'2021-05-06 12:00:00','2021-06-06 12:00:00',7,FALSE,TRUE,FALSE,1678,90,402,1,8);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (14,'2021-05-07 12:00:00','2021-06-07 12:00:00',8,TRUE,TRUE,FALSE,1357.11,403,3,9);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (15,'2021-05-08 12:00:00','2021-06-08 12:00:00',9,FALSE,TRUE,TRUE,1314.15,404,2,7);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (16,'2021-05-09 12:00:00','2021-06-09 12:00:00',10,TRUE,TRUE,TRUE,1248.16,501,2,2);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (17,'2021-05-01 12:00:00','2021-06-01 12:00:00',11,FALSE,TRUE,FALSE,2468.10,502,3,4);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (18,'2021-05-02 12:00:00','2021-06-02 12:00:00',2,TRUE,TRUE,TRUE,2345.67,503,2,2);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (19,'2021-05-03 12:00:00','2021-06-03 12:00:00',3,FALSE,TRUE,FALSE,15000.45,504,1,5);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (20,'2021-05-04 12:00:00','2021-06-04 12:00:00',5,TRUE,TRUE,FALSE,5101.55,601,1,8);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (21,'2021-05-05 12:00:00','2021-06-05 12:00:00',7,FALSE,TRUE,FALSE,1625.25,602,3,0);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (22,'2021-05-06 12:00:00','2021-06-06 12:00:00',11,TRUE,TRUE,FALSE,985.34,603,3,6);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (23,'2021-05-07 12:00:00','2021-06-07 12:00:00',13,FALSE,TRUE,TRUE,4500.13,604,1,1);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (24,'2021-05-08 12:00:00','2021-06-08 12:00:00',17,TRUE,TRUE,TRUE,13956.23,701,1,1);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (25,'2021-05-09 12:00:00','2021-06-09 12:00:00',19,FALSE,TRUE,TRUE,8471.49,702,2,6);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (26,'2021-05-10 12:00:00','2021-06-10 12:00:00',2,TRUE,TRUE,TRUE,5469.19,703,1,4);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (27,'2021-05-01 12:00:00','2021-06-01 12:00:00',4,FALSE,TRUE,FALSE,3216.48,704,3,5);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (28,'2021-05-02 12:00:00','2021-06-02 12:00:00',8,TRUE,TRUE,TRUE,7316.36,801,3,7);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (29,'2021-05-03 12:00:00','2021-06-03 12:00:00',16,FALSE,TRUE,TRUE,4897.21,802,1,3);
INSERT INTO OFERTA (ID_OFERTA,DATA_START,DATA_END,CAPACIDADE_QUARTO,WIFI,AR_CONDICIONADO,CAFE,PRECO,NUMERO_QUARTO,ID_SITE,ID_HOTEL) VALUES (30,'2021-05-04 12:00:00','2021-06-04 12:00:00',6,TRUE,TRUE,TRUE,7893.27,803,1,13);

INSERT INTO RESERVA (ID_RESERVA,CPF_CLIENTE,NOME_CLIENTE,ADULTOS,CRIANCAS,RESERVA_START,RESERVA_END,ID_OFERTA) VALUES (0,'64095363134','Ruan Nicolas Daniel da Paz',2,2,'2021-05-03 12:00:00','2021-06-03 12:00:00',10);
INSERT INTO RESERVA (ID_RESERVA,CPF_CLIENTE,NOME_CLIENTE,ADULTOS,CRIANCAS,RESERVA_START,RESERVA_END,ID_OFERTA) VALUES (1,'91394069545','Luciana Mirella Mendes',3,0,'2021-05-02 12:00:00','2021-06-02 12:00:00',9);
INSERT INTO RESERVA (ID_RESERVA,CPF_CLIENTE,NOME_CLIENTE,ADULTOS,CRIANCAS,RESERVA_START,RESERVA_END,ID_OFERTA) VALUES (2,'38778635748','Lorena Isabel Pereira',11,0,'2021-05-01 12:00:00','2021-06-01 12:00:00',8);
INSERT INTO RESERVA (ID_RESERVA,CPF_CLIENTE,NOME_CLIENTE,ADULTOS,CRIANCAS,RESERVA_START,RESERVA_END,ID_OFERTA) VALUES (3,'42600401032','Noah Erick César das Neves',7,0,'2021-05-08 12:00:00','2021-06-08 12:00:00',7);
INSERT INTO RESERVA (ID_RESERVA,CPF_CLIENTE,NOME_CLIENTE,ADULTOS,CRIANCAS,RESERVA_START,RESERVA_END,ID_OFERTA) VALUES (4,'61983165646','Luiz Gustavo Márcio Almeida',2,3,'2021-05-07 12:00:00','2021-06-07 12:00:00',6);
INSERT INTO RESERVA (ID_RESERVA,CPF_CLIENTE,NOME_CLIENTE,ADULTOS,CRIANCAS,RESERVA_START,RESERVA_END,ID_OFERTA) VALUES (5,'11631307703','Hugo Manoel Barbosa',2,1,'2021-05-06 12:00:00','2021-06-06 12:00:00',5);
INSERT INTO RESERVA (ID_RESERVA,CPF_CLIENTE,NOME_CLIENTE,ADULTOS,CRIANCAS,RESERVA_START,RESERVA_END,ID_OFERTA) VALUES (6,'28966721761','Milena Elaine da Paz',1,1,'2021-05-05 12:00:00','2021-06-05 12:00:00',4);
INSERT INTO RESERVA (ID_RESERVA,CPF_CLIENTE,NOME_CLIENTE,ADULTOS,CRIANCAS,RESERVA_START,RESERVA_END,ID_OFERTA) VALUES (7,'03696064858','Raquel Josefa Melissa da Cunha',6,10,'2021-05-04 12:00:00','2021-06-04 12:00:00',3);
INSERT INTO RESERVA (ID_RESERVA,CPF_CLIENTE,NOME_CLIENTE,ADULTOS,CRIANCAS,RESERVA_START,RESERVA_END,ID_OFERTA) VALUES (8,'88027867983','Rafaela Luana Rezende',3,5,'2021-05-03 12:00:00','2021-06-03 12:00:00',2);
INSERT INTO RESERVA (ID_RESERVA,CPF_CLIENTE,NOME_CLIENTE,ADULTOS,CRIANCAS,RESERVA_START,RESERVA_END,ID_OFERTA) VALUES (9,'80100065309','Carlos Cauê João Pinto',2,2,'2021-05-02 12:00:00','2021-06-02 12:00:00',1);
INSERT INTO RESERVA (ID_RESERVA,CPF_CLIENTE,NOME_CLIENTE,ADULTOS,CRIANCAS,RESERVA_START,RESERVA_END,ID_OFERTA) VALUES (10,'53293692079','Mariane Beatriz Viana',2,0,'2021-05-01 12:00:00','2021-06-01 12:00:00',0);
