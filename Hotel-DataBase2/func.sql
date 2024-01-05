CREATE OR REPLACE FUNCTION ocupacaoHotel(integer)
RETURNS TABLE(id_hotel integer, vagas_totais integer, vagas_livre integer, vagas_ocupadas integer, porcentagem numeric)
AS $$
DECLARE
    cursor_ocupacao CURSOR FOR
        SELECT O.CAPACIDADE_QUARTO, R.ID_RESERVA FROM OFERTA O FULL OUTER JOIN RESERVA R ON (O.ID_OFERTA=R.ID_OFERTA)
        WHERE (O.ID_HOTEL=$1) AND (O.DATA_START >= CURRENT_DATE);
    nvagas INTEGER;
    ocupadas INTEGER;
    livres INTEGER;
    idres INTEGER;
    cquarto INTEGER;
    porcentagem NUMERIC;
BEGIN
	nvagas:=0;
	ocupadas:=0;
    OPEN cursor_ocupacao;
    LOOP
        FETCH NEXT FROM cursor_ocupacao
            INTO cquarto,idres;
        EXIT WHEN NOT FOUND;

        IF idres IS NOT NULL THEN
            ocupadas := ocupadas + cquarto;
        END IF;
        nvagas:=nvagas+cquarto;
    END LOOP;
    CLOSE cursor_ocupacao;
    livres:=nvagas-ocupadas;
    porcentagem:=((ocupadas/nvagas)*100);
    RETURN QUERY VALUES ($1, nvagas, livres, ocupadas, porcentagem);
END;

$$ LANGUAGE plpgsql;

--SELECT (ocupacaoHotel(1)).*;

CREATE OR REPLACE FUNCTION ofertasDisponiveis(integer, integer, numeric)
RETURNS TABLE(id_oferta integer,id_site integer,id_hotel integer,data_start timestamp,data_end timestamp,capacidade_quarto integer,wifi boolean,ar_condicionado boolean,cafe boolean,preco numeric,numero_quarto integer)
AS $$
SELECT * FROM OFERTA O
WHERE O.ID_OFERTA IN  (SELECT O.ID_OFERTA FROM OFERTA O FULL OUTER JOIN RESERVA R ON (O.ID_OFERTA=R.ID_OFERTA)

        WHERE (O.ID_HOTEL=$1) AND (O.DATA_START >= CURRENT_DATE)

 AND (R.ID_RESERVA IS NULL) AND (O.CAPACIDADE_QUARTO>=$2) AND (O.PRECO<=$3));

$$ LANGUAGE SQL;

-- SELECT (ofertasDisponiveis(1, 5, 5000)).*;




SELECT e.nome as estado ,c.nome as cidade, h.nome as hotel, o.capacidade_quarto ,o.numero_quarto, o.preco
from hotel h,oferta o, cidade c, estado e
where e.uf = c.estado_uf and c.id_cidade = h.id_cidade and h.id_hotel = o.id_hotel 
and o.data_start > CURRENT_DATE 
and not exists(SELECT * from reserva r 
where o.id_oferta = r.id_oferta)
order by e.nome;

CREATE VIEW viewSitesCidades
AS
(
SELECT s.ID_SITE AS id, s.NOME AS nome_de_site, URL AS url, e.UF, c.NOME AS cidade FROM SITE s, POSSUI p, ESTADO e, CIDADE c
WHERE (s.ID_SITE = p.ID_SITE) AND (e.UF = p.ESTADO_UF) AND (c.ESTADO_UF = e.UF)
order by s.ID_SITE, e.UF, c.NOME;
);

CREATE VIEW viewAvalicaoHotel
AS
(
SELECT h.ID_HOTEL, c.ESTADO_UF AS UF, c.NOME AS cidade, h.DESCRICAO, h.NOTA_MEDIA, a.NOTA, a.AVALIACAO FROM CIDADE c, HOTEL h, AVALIACAO a
WHERE (c.ID_CIDADE = h.ID_CIDADE) AND (h.ID_HOTEL = a.ID_HOTEL)
order by h.ID_HOTEL,a.NOTA;
);

CREATE OR REPLACE FUNCTION precosHotel(integer,numeric)
RETURN TABLE()
AS $$
DECLARE
BEGIN
	SELECT O.CAPACIDADE_QUARTO, R.ID_RESERVA FROM OFERTA O FULL OUTER JOIN RESERVA R ON (O.ID_OFERTA=R.ID_OFERTA)
        WHERE (O.ID_HOTEL=$1) AND (O.DATA_START >= CURRENT_DATE);
END;
