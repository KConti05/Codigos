USE falls_car;

INSERT INTO cliente(nome,cpf_cnpj,email,senha_hash,cnh,telefone) VALUES ("Thiago Tavares","00000000001","thiago@gmail.com","1234","00000000001","21900030003");
INSERT INTO funcionario(nome,cpf,email,senha_hash,funcao) VALUES ("Marcio Belo","00000000012","belo@gmail.com","2425","motorista");
INSERT INTO motorista(id_funcionario,nome,cnh,diaria) VALUES (1,"Marcio Belo","00000000012",124.15);
INSERT INTO modelo(nome,marca,ano,categoria,preco_padrao) VALUES ("Onix","Chevrolet","2020","Hatch",130.29);
INSERT INTO loja(nome,endereco,cidade,uf,telefone) VALUES ("Loja Suvaco Seco","Rua SB, numero 413","Carpazinha","RS","21941300413");
INSERT INTO carro(id_modelo,id_loja,placa,automatico,valor,status) VALUES (1,1,"ABC1234",TRUE,150.29,"livre");
INSERT INTO seguro(nome,cobert_avariada,cobert_perda_total,compensacao_CO2,valor) VALUES ("Seguro Padrão",TRUE,TRUE,TRUE,59.99);
INSERT INTO locacao(id_cliente,id_motorista,id_carro,id_loja_retirada,id_loja_devolucao,id_seguro,data_locacao,data_devolucao,motorista_aparte,status,valor_total,canal)
  VALUES(1,1,1,1,1,1,"2025-12-01 12:00:00","2025-12-16 12:00:00",TRUE,"reservada",4176.59,"balcão");
INSERT INTO pagamento(id_cliente,data_pagamento,valor_pago,num_parcelas,status) VALUES (1,"2025-11-29 21:53:42",4176.59,4,"pendente");
INSERT INTO locacaoPagamento(id_pagamento,id_locacao) VALUES (1,1);

SELECT pagamento.id_cliente,locacaoPagamento.id_locacao
FROM pagamento
JOIN locacaoPagamento on pagamento.id=locacaoPagamento.id_pagamento;

UPDATE pagamento
SET status="confirmado"
WHERE id=1;

DELETE FROM pagamento WHERE id=1;
DELETE FROM locacaoPagamento WHERE id=1;
