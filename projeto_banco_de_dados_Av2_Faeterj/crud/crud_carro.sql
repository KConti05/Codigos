USE falls_car;

INSERT INTO modelo(nome,marca,ano,categoria,preco_padrao) VALUES ("Onix","Chevrolet","2020","Hatch",130.29);
INSERT INTO loja(nome,endereco,cidade,uf,telefone) VALUES ("Loja Suvaco Seco","Rua SB, numero 413","Carpazinha","RS","21941300413");
INSERT INTO carro(id_modelo,id_loja,placa,automatico,valor,status) VALUES (1,1,"ABC1234",TRUE,150.29,"livre");

SELECT placa,automatico,valor FROM carro WHERE status="livre";

UPDATE carro
SET status="alocado"
WHERE placa="ABC1234";

DELETE FROM carro WHERE status="alocado";
