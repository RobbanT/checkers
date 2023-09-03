![Checkers](/checkers.png)
Spelet Checkers är ett brädspel som spelas av två spelare (Spelare 1 och Spelare 2). Varje spelare har 12 brickor och målet är att en av spelarna antingen ska lyckas få bort moståndarspelarens alla brickor från spelbrädet eller lyckas göra så att moståndarspelaren inte längre kan flytta några av sina brickor. Spelare 1:s brickor är markerade med 'x' och 'X' . Spelare 2:s brickor är markerade med 'o' och 'O'.

Vid ett nytt spel börjar alltid Spelare 1. När en spelare ska flytta en av sina brickor måste alltid koordinaterna (rad och kolumn) anges för rutan som brickan befinner sig. Sedan måste koordinaterna för rutan som man vill flytta brickan till anges. När detta är gjort är det nästa spelares tur om inte ett så kallat dubbelhopp kan utföras efter ett utfört hopp (mer om detta nedan).

Ens brickor kan endast flyttas diagonalt ett steg framåt till en ledig ruta. Alternativt kan en bricka flyttas två steg framåt om man utför ett så kallat hopp över en ruta som en av motståndarspelarens brickor befinner sig i. Notera att rutan som man hoppar till måste vara ledig.

Utförs ett hopp så tas brickan bort som man hoppade över. Skulle det visa sig att ännu ett hopp kan utföras efter ett utfört hopp så får man hoppa igen med samma bricka. Detta är ett så kallat dubbelhopp och fungerar på samma sätt som ett vanligt hopp. Skillnaden är dock att ett sådant hopp alltid måste utföras.

Båda spelarnas brickor kan ha två olika typer av status. Antingen är en bricka okrönt (markeras med 'x' och 'o') eller så är en bricka krönt (markeras med 'X' och 'O'). Skillnaden mellan okrönta och krönta brickor är att okrönta brickor endast kan röra sig framåt medan krönta brickor kan röra sig både framåt och bakåt.

Som standard är alla brickor okrönta i början av ett nytt spel. För att en bricka ska bli krönt måste den nå den sista raden på spelbrädet. Mer exakt måste någon av Spelare 1:s brickor nå rad 8 och någon av Spelare 2:s brickor måste nå rad 1.

Notera att om en bricka skulle bli krönt efter ett hopp så kan inte denna bricka utföra något dubbelhopp trots att det skulle vara möjligt med en okrönt bricka.
