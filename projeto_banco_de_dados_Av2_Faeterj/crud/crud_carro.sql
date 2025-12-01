USE falls_car;

INSERT INTO carro(nome,marca,ano,categoria,preco_padrao) VALUES ("Onix","Chevrolet","2020","Hatch",130.29),("Corolla","Toyota","2025","Sedan",230.42),("320i","BMW","2023","Sedan",720.00);

SELECT * FROM carro WHERE categoria="Sedan";

UPDATE FROM carro
SET preco_padrao=preco_padrao+100.00
WHERE categoria="Sedan";

DELETE FROM carro WHERE preco_padrao<200.00;
