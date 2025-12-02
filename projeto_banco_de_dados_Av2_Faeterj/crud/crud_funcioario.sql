USE falls_car;

INSERT INTO funcionario(nome,cpf,email,senha_hash,funcao) 
  VALUES ("Marcio Belo","00000000012","belo@gmail.com","2425","professor de 3POB"),("Claudio Bispo","00000000011","bispo@gmail.com","4245","professor de 3ALG");

SELECT id,nome,email FROM funcionario WHERE funcao="professor de 3POB";

UPDATE funcionario
SET cpf="00000000010"
WHERE id=1;

SELECT id,nome,email FROM funcionario WHERE funcao="professor de 3POB";
DELETE FROM funcionario WHERE id=1;
SELECT * FROM funcionario;

DELETE FROM funcionario;
