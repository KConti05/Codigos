USE falls_car;

INSERT INTO modelo(nome,marca,ano,categoria,preco_padrao) VALUES ("Onix","Chevrolet","2020","Hatch",130.29);
INSERT INTO loja(nome,endereco,cidade,uf,telefone) VALUES ("Loja Suvaco Seco","Rua SB, numero 413","Carpazinha","RS");
INSERT INTO carro(id_modelo,id_loja,placa,automatico,valor,status) VALUES (1,1,"ABC1234",TRUE,150.29,"em manutenção");
INSERT INTO manutencao(id_carro,data_entrada,data_saida,valor,descricao_servicos) VALUES (1,"2025-11-29 10:41:00","2025-12-06 12:00:00", 100.00, "revisão");

SELECT id_carro,data_entrada,data_saida,descricao_servicos FROM manutencao WHERE valor>50.00;

UPDATE FROM manutencao
SET data_saida="2025-12-08 12:31:00"
SET valor=250.00
SET descricao_servicos="revisão+troca de suspensão"
WHERE id_carro=1;

DELETE FROM manutencao WHERE id_carro=1;
