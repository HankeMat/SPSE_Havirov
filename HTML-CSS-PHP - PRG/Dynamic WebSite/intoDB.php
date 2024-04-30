<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login page</title>
</head>
<body>
    <h1>Login:</h1>
    <br>
    <table>
        <form action="" method="post">
        <tr>
            <td><h3>Personal information:</h3></td>
        </tr>
        <tr>
            <td><label for="name">Name: </label></td>
            <td><input type="text" name="name" require></td>
        </tr>
        <tr>
            <td><label for="surname">Surname: </label></td>
            <td><input type="text" name="surname"></td>
        </tr>
        <tr>
            <td><label for="age">Age: </label></td>
            <td><input type="number" name="age" require min="1" max="100"></td>
        </tr>
        <tr>
            <td><label for="town">Town: </label></td>
            <td>
                <select name="town">
                    <option value="Praha">Praha</option>
                    <option value="Brno">Brno</option>
                    <option value="Ostrava">Ostrava</option>
                    <option value="Plzeň">Plzeň</option>
                    <option value="Liberec">Liberec</option>
                    <option value="Olomouc">Olomouc</option>
                    <option value="Ústí nad Labem">Ústí nad Labem</option>
                    <option value="Hradec Králové">Hradec Králové</option>
                    <option value="České Budějovice">České Budějovice</option>
                    <option value="Pardubice">Pardubice</option>
                    <option value="Havířov">Havířov</option>
                    <option value="Zlín">Zlín</option>
                    <option value="Kladno">Kladno</option>
                    <option value="Most">Most</option>
                    <option value="Karviná">Karviná</option>
                    <option value="Opava">Opava</option>
                    <option value="Frýdek-Místek">Frýdek-Místek</option>
                    <option value="Jihlava">Jihlava</option>
                    <option value="Teplice">Teplice</option>
                    <option value="Děčín">Děčín</option>
                    <option value="Chomutov">Chomutov</option>
                    <option value="Přerov">Přerov</option>
                    <option value="Mladá Boleslav">Mladá Boleslav</option>
                    <option value="Prostějov">Prostějov</option>
                    <option value="Písek">Písek</option>
                    <option value="Tábor">Tábor</option>
                    <option value="Trutnov">Trutnov</option>
                    <option value="Cheb">Cheb</option>
                    <option value="Vsetín">Vsetín</option>
                    <option value="Kroměříž">Kroměříž</option>
                    <option value="Uherský Brod">Uherský Brod</option>
                    <option value="Litvínov">Litvínov</option>
                    <option value="Nový Jičín">Nový Jičín</option>
                    <option value="Hodonín">Hodonín</option>
                    <option value="Chrudim">Chrudim</option>
                    <option value="Šumperk">Šumperk</option>
                    <option value="Uherské Hradiště">Uherské Hradiště</option>
                    <option value="Jablonec nad Nisou">Jablonec nad Nisou</option>
                    <option value="Kutná Hora">Kutná Hora</option>
                    <option value="Náchod">Náchod</option>
                    <!-- And so on.. :D-->
                </select>
            </td>
        </tr>
        <tr>
            <td><h3>Education:</h3></td>
        </tr>
        <tr>
            <td><label for="education">University: </label></td>
            <td><input type="radio" name="education" value="University"></td>
        </tr>
        <tr>
            <td><label for="education">High: </label></td>
            <td><input type="radio" name="education" value="High"></td>
        </tr>
        <tr>
            <td><label for="education">Elementary: </label></td>
            <td><input type="radio" name="education" value="Elementary"></td>
        </tr>
        <tr>
            <td><label for="agree">Agreement: </label></td>
            <td><input type="checkbox" name="agree"></td>
        </tr>
        <tr>
            <td><input type="submit" value="Send"></td>
        </tr>
        </form>
    </table> 

    <?php
        if ($_POST) {
            if (isset($_POST["agree"])) {

                $name = $_POST["name"];
                $surname = $_POST["surname"];
                $age = $_POST["age"];
                $town = $_POST["town"];
                $education = $_POST["education"]; 

                include "connection.php";
                $sqlAddToDB = "INSERT INTO test_table (name, surname, age, town, education) VALUES ('$name', '$surname', '$age', '$town', '$education')";
                mysqli_query($connection, $sqlAddToDB);
                echo "Data has been sent";
                mysqli_close($connection);
            }else{
                echo "You haven´t agreed to use of your personal information";
            }
        }
    ?>
</body>
</html>