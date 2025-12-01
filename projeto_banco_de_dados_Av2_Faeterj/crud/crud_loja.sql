USE falls_car;

INSERT INTO loja(nome,endereco,cidade,uf,telefone) VALUES ("Loja Suvaco Seco","Rua SB, numero 413","Carpazinha","RS");

SELECT id FROM loja WHERE uf="RS";

UPDATE FROM loja
SET endereco="Rua Projeto SB, numero 413"
WHERE id=1;

DELETE FROM loja WHERE nome="Loja Suvaco Seco";
