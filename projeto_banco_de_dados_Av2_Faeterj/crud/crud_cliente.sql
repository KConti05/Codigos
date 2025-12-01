USE falls_car;

INSERT INTO cliente(nome,cpf_cnpj,email,senha_hash,cnh,telefone) 
VALUES ("Thiago Tavares","00000000001","thiago@gmail.com","1234","00000000001","21900030003"),("Vitor Medeiros","0000000002","vitor@gmail.com","4321","00000000002","21900020002");

SELECT nome,cnh,email,telefone FROM cliente WHERE id=1;

UPDATE cliente
SET telefone="21900030003"
WHERE id=1;

SELECT nome,cnh,email,telefone FROM cliente WHERE id=2;
DELETE FROM cliente WHERE id=2;
SELECT * FROM cliente;

DELETE FROM cliente;
