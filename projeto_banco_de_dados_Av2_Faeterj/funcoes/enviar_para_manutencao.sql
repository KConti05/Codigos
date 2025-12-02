USE falls_car;

INSERT INTO modelo(nome,marca,ano,categoria,preco_padrao) VALUES ("Onix","Chevrolet","2020","Hatch",130.29);
INSERT INTO loja(nome,endereco,cidade,uf,telefone) VALUES ("Loja Suvaco Seco","Rua SB, numero 413","Carpazinha","RS");
INSERT INTO carro(id_modelo,id_loja,placa,automatico,valor,status) VALUES (1,1,"ABC1234",TRUE,150.29,"livre");

INSERT INTO manutencao(id_carro,data_entrada,data_saida,valor,descricao_servicos) VALUES (1,NOW(),"2025-12-05 12:00:00",150.00,"revisao apos ser devolvido");
UPDATE carro
SET status="em manutencao"
WHERE id=1;
