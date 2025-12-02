USE falls_car;

INSERT INTO modelo(nome,marca,ano,categoria,preco_padrao) VALUES ("Onix","Chevrolet","2020","Hatch",130.29),("Corolla","Toyota","2025","Sedan",230.42),("320i","BMW","2023","Sedan",720.00);

SELECT * FROM modelo WHERE categoria="Sedan";

UPDATE FROM modelo
SET preco_padrao=preco_padrao+100.00
WHERE categoria="Sedan";

DELETE FROM modelo WHERE preco_padrao<200.00;
