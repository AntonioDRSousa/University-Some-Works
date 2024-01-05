INSERT INTO PESSOA (CPF, NOME, TIPO) VALUES ('64095363134','Ruan Nicolas Daniel da Paz','hospede');
INSERT INTO PESSOA (CPF, NOME, TIPO) VALUES ('91394069545','Luciana Mirella Mendes','hospede');
INSERT INTO PESSOA (CPF, NOME, TIPO) VALUES ('38778635748','Lorena Isabel Pereira','hospede');
INSERT INTO PESSOA (CPF, NOME, TIPO) VALUES ('42600401032','Noah Erick César das Neves','hospede');
INSERT INTO PESSOA (CPF, NOME, TIPO) VALUES ('61983165646','Luiz Gustavo Márcio Almeida','hospede');
INSERT INTO PESSOA (CPF, NOME, TIPO) VALUES ('11631307703','Hugo Manoel Barbosa','hospede');
INSERT INTO PESSOA (CPF, NOME, TIPO) VALUES ('28966721761','Milena Elaine da Paz','hospede');

INSERT INTO PESSOA (CPF, NOME, TIPO) VALUES ('03696064858','Raquel Josefa Melissa da Cunha','funcionario');
INSERT INTO PESSOA (CPF, NOME, TIPO) VALUES ('88027867983','Rafaela Luana Rezende','funcionario');
INSERT INTO PESSOA (CPF, NOME, TIPO) VALUES ('80100065309','Carlos Cauê João Pinto','funcionario');
INSERT INTO PESSOA (CPF, NOME, TIPO) VALUES ('53293692079','Mariane Beatriz Viana','funcionario');
INSERT INTO PESSOA (CPF, NOME, TIPO) VALUES ('45522353708','Louise Regina Jenifer Nogueira','funcionario');
INSERT INTO PESSOA (CPF, NOME, TIPO) VALUES ('43943249719','Pedro Henrique Eric Cavalcanti','funcionario');
INSERT INTO PESSOA (CPF, NOME, TIPO) VALUES ('74575470708','Oliver Benedito Araújo','funcionario');

INSERT INTO HOSPEDE (CPF, ENDERECO) VALUES ('64095363134','Rua Frei João, numero 155');
INSERT INTO HOSPEDE (CPF, ENDERECO) VALUES ('91394069545','Rua Major Doutor Azevedo, numero 286');
INSERT INTO HOSPEDE (CPF, ENDERECO) VALUES ('38778635748','Rua Afonso Pena, numero 671');
INSERT INTO HOSPEDE (CPF, ENDERECO) VALUES ('42600401032','Rua Conde Afonso Celso, numero 664');
INSERT INTO HOSPEDE (CPF, ENDERECO) VALUES ('61983165646','Rua das Hortencias, numero 790');
INSERT INTO HOSPEDE (CPF, ENDERECO) VALUES ('11631307703','Rua Nova, numero 277');
INSERT INTO HOSPEDE (CPF, ENDERECO) VALUES ('28966721761','Rua São Benedito, numero 574');

INSERT INTO TELEFONE (CPF, NUM_TELEFONE) VALUES ('64095363134','988970227');
INSERT INTO TELEFONE (CPF, NUM_TELEFONE) VALUES ('91394069545','997639087');
INSERT INTO TELEFONE (CPF, NUM_TELEFONE) VALUES ('91394069545','982399676');
INSERT INTO TELEFONE (CPF, NUM_TELEFONE) VALUES ('38778635748','999568265');
INSERT INTO TELEFONE (CPF, NUM_TELEFONE) VALUES ('42600401032','998436137');
INSERT INTO TELEFONE (CPF, NUM_TELEFONE) VALUES ('61983165646','996548325');
INSERT INTO TELEFONE (CPF, NUM_TELEFONE) VALUES ('61983165646','985233936');
INSERT INTO TELEFONE (CPF, NUM_TELEFONE) VALUES ('11631307703','999993954');
INSERT INTO TELEFONE (CPF, NUM_TELEFONE) VALUES ('28966721761','986988292');

INSERT INTO SERVICOS (COD_SERVICO, PRECO, DESCRICAO) VALUES (1,0,'recepcao');
INSERT INTO SERVICOS (COD_SERVICO, PRECO, DESCRICAO) VALUES (2,0,'limpeza');
INSERT INTO SERVICOS (COD_SERVICO, PRECO, DESCRICAO) VALUES (3,50,'servicos de cozinha');
INSERT INTO SERVICOS (COD_SERVICO, PRECO, DESCRICAO) VALUES (4,70,'armazenamento em cofre');
INSERT INTO SERVICOS (COD_SERVICO, PRECO, DESCRICAO) VALUES (5,200,'evento cultural');
INSERT INTO SERVICOS (COD_SERVICO, PRECO, DESCRICAO) VALUES (6,60,'lavanderia');
INSERT INTO SERVICOS (COD_SERVICO, PRECO, DESCRICAO) VALUES (7,80,'servicos de quarto');

INSERT INTO QUARTO (NUM_QUARTO, TIPO, OCUPADO, CAPACIDADE, CUSTO_ADICIONAL) VALUES (101,'dormitorio',TRUE,10,0);
INSERT INTO QUARTO (NUM_QUARTO, TIPO, OCUPADO, CAPACIDADE, CUSTO_ADICIONAL) VALUES (102,'standard',FALSE,5,0);
INSERT INTO QUARTO (NUM_QUARTO, TIPO, OCUPADO, CAPACIDADE, CUSTO_ADICIONAL) VALUES (103,'dormitorio',TRUE,15,50);
INSERT INTO QUARTO (NUM_QUARTO, TIPO, OCUPADO, CAPACIDADE, CUSTO_ADICIONAL) VALUES (201,'master',FALSE,5,0);
INSERT INTO QUARTO (NUM_QUARTO, TIPO, OCUPADO, CAPACIDADE, CUSTO_ADICIONAL) VALUES (202,'standard',FALSE,4,0);
INSERT INTO QUARTO (NUM_QUARTO, TIPO, OCUPADO, CAPACIDADE, CUSTO_ADICIONAL) VALUES (203,'master',TRUE,6,80);

INSERT INTO OFERECE (NUM_QUARTO, COD_SERVICO, DATA_EVENTO) VALUES (201,1,'2020-10-20 12:00:00');
INSERT INTO OFERECE (NUM_QUARTO, COD_SERVICO, DATA_EVENTO) VALUES (102,1,'2020-10-20 12:00:00');

INSERT INTO OFERECE (NUM_QUARTO, COD_SERVICO, DATA_EVENTO) VALUES (101,1,'2020-11-10 12:00:00');
INSERT INTO OFERECE (NUM_QUARTO, COD_SERVICO, DATA_EVENTO) VALUES (103,1,'2020-11-15 12:00:00');
INSERT INTO OFERECE (NUM_QUARTO, COD_SERVICO, DATA_EVENTO) VALUES (103,3,'2020-11-22 13:00:00');
INSERT INTO OFERECE (NUM_QUARTO, COD_SERVICO, DATA_EVENTO) VALUES (203,1,'2020-11-20 12:00:00');
INSERT INTO OFERECE (NUM_QUARTO, COD_SERVICO, DATA_EVENTO) VALUES (203,7,'2020-11-25 16:00:00');

INSERT INTO FUNCIONARIO (CPF, COD_SERVICO, CADASTRADO_POR_CPF) VALUES ('03696064858',1,null);
INSERT INTO FUNCIONARIO (CPF, COD_SERVICO, CADASTRADO_POR_CPF) VALUES ('88027867983',2,'03696064858');
INSERT INTO FUNCIONARIO (CPF, COD_SERVICO, CADASTRADO_POR_CPF) VALUES ('80100065309',3,null);
INSERT INTO FUNCIONARIO (CPF, COD_SERVICO, CADASTRADO_POR_CPF) VALUES ('53293692079',4,'03696064858');
INSERT INTO FUNCIONARIO (CPF, COD_SERVICO, CADASTRADO_POR_CPF) VALUES ('45522353708',5,'80100065309');
INSERT INTO FUNCIONARIO (CPF, COD_SERVICO, CADASTRADO_POR_CPF) VALUES ('43943249719',6,'53293692079');
INSERT INTO FUNCIONARIO (CPF, COD_SERVICO, CADASTRADO_POR_CPF) VALUES ('74575470708',7,'43943249719');

INSERT INTO FICHA 
(
	COD_FICHA, CPF_FUNC, NUM_QUARTO, CUSTO_BASE, QTD_HOSPEDES, CHECK_IN, CHECK_OUT
) 
VALUES 
(
	1,'03696064858',102,750,1,'2020-10-20 12:00:00','2020-10-30 12:00:00'

);

INSERT INTO FICHA 
(
	COD_FICHA, CPF_FUNC, NUM_QUARTO, CUSTO_BASE, QTD_HOSPEDES, CHECK_IN, CHECK_OUT
) 
VALUES 
(
	2,'03696064858',201,1000,2,'2020-10-20 12:00:00','2020-10-25 12:00:00'
);


INSERT INTO FICHA 
(
	COD_FICHA, CPF_FUNC, NUM_QUARTO, CUSTO_BASE, QTD_HOSPEDES, CHECK_IN, CHECK_OUT
) 
VALUES 
(
	3,'03696064858',101,4500,3,'2020-11-10  12:00:00','2020-12-10 12:00:00'
);

INSERT INTO FICHA 
(
	COD_FICHA, CPF_FUNC, NUM_QUARTO, CUSTO_BASE, QTD_HOSPEDES, CHECK_IN, CHECK_OUT
) 
VALUES 
(
	4,'03696064858',103,2000,2,'2020-11-15  12:00:00','2020-12-05 12:00:00'
);

INSERT INTO FICHA 
(
	COD_FICHA, CPF_FUNC, NUM_QUARTO, CUSTO_BASE, QTD_HOSPEDES, CHECK_IN, CHECK_OUT
) 
VALUES 
(
	5,'03696064858',203,1100,1,'2020-11-20  12:00:00','2020-12-01 12:00:00'
);

INSERT INTO POSSUI (CPF,COD_FICHA) VALUES ('28966721761',1);
INSERT INTO POSSUI (CPF,COD_FICHA) VALUES ('42600401032',2);
INSERT INTO POSSUI (CPF,COD_FICHA) VALUES ('38778635748',2);
INSERT INTO POSSUI (CPF,COD_FICHA) VALUES ('64095363134',3);
INSERT INTO POSSUI (CPF,COD_FICHA) VALUES ('91394069545',3);
INSERT INTO POSSUI (CPF,COD_FICHA) VALUES ('38778635748',3);
INSERT INTO POSSUI (CPF,COD_FICHA) VALUES ('42600401032',4);
INSERT INTO POSSUI (CPF,COD_FICHA) VALUES ('61983165646',4);
INSERT INTO POSSUI (CPF,COD_FICHA) VALUES ('11631307703',5);
