USE falls_car;

INSERT INTO funcionario(nome,cpf,email,senha_hash,funcao) 
  VALUES ("Wagner Zanco","00000000029","zanco@gmail.com","7890","motorista"),("Eduardo Barreto","00000000030","barreto@gmail.com","9001","motorista");
INSERT INTO motorista(id_funcionario,nome,cnh,diaria) 
  VALUES (1,"Wagner Zanco","00000000029",124.15);

UPDATE FROM motorista
SET id_funcionario=2,nome="Eduardo Barreto",cnh="00000000030",diaria=169.98)
WHERE id=1;

DELETE FROM motorista WHERE id=1;
