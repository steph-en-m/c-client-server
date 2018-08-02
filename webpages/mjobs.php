<?php 
function getconn(){
return mysql_connect("localhost:3306","root","hassan");
}

function msg($p){
echo($p);	
	
}

function display(){
if($_POST['choice']=="HOME"){
msg("<table name=\"home\" border=\"1\" align=\"center\"><caption>Currently Executing Jobs</caption><tr><th>Sno</th><th>Command Name</th><th>Command Argument</th></tr>");
	
$q="select pending.typeOftask,pending.body from pending where pending.ordering=1";
$conn= getconn();
if(mysql_select_db("wordserver")!=0)echo(mysql_error());

if(!$rset=mysql_query($q,$conn))die(msql_error());
else{

for($i=0;$i<mysql_num_rows($rset);$i++){
$rows=mysql_fetch_row($rset);
echo("<tr>");
$ii = $i+1;
msg("<td>".$ii."</td>");
$g = $rows[0]==0?"replace":($rows[0]==1?"delete":($rows[0]==2?"encrypt":($rows[0]==3?"decrypt":($rows[0]==4?"reverse":"double"))));
msg("<td>".$g."</td>");
msg("<td>".$rows[1]."</td>");
msg("</tr>");

}
}


msg("</table>");
}
else if($_POST['choice']=="Average Processing Time"){
msg("<p style=\"font-size:50px\">Average Time at this instabce</p>");
$qt="select taskid,timecomplete,timepost from ready,pending where ready.taskid=pending.idno ";
$conn=getconn();
if(mysql_select_db("wordserver")!=0)msg(mysql_error());
if(!$rs=mysql_query($qt,$conn))msg(mysql_error());

else{
$totaljobs=mysql_num_rows($rs);$tfin=0;
for($i=0;$i<mysql_num_rows($rs);$i++){
$qrw=mysql_fetch_row($rs);
$tfin = $tfin + ($qrw[1]-$qrw[2]);
}
}
$avgtime=$totaljobs==0?0:($tfin/$totaljobs);
msg("Number of success jobs: ".$totaljobs."<br \>");

msg("Total time spent to process Jobs: ".$tfin."<br \>");
msg("Average time spent for processing: ".$avgtime."<br \>");
}

else if($_POST['choice']=="Successful Jobs"){
$conn = getconn();
if(!mysql_select_db("wordserver"))msg("database selection failed!...........");
$rset="select typeOftask from pending where status=2";
$query=mysql_query($rset,$conn);
$rpl=0;$del=0;$enc=0;$dec=0;$doub=0;$rev=0;$reply=0;
msg("<center><table border=\"1\"><caption> Successful Jobs...</caption>");

for($i=0;$i<mysql_num_rows($query);$i++){
$rw=mysql_fetch_row($query);
if($rw[0]==0)$rpl++;
else if($rw[0]==1)$del++;
else if($rw[0]==2)$enc++;
else if($rw[0]==3)$dec++;
else if($rw[0]==4)$rev++;
else if($rw[0]==5)$doub++;

else$reply++;
}
msg("<tr><th>Sno</th><th>Command Category</th><th>Number</th></tr>");
msg("<tr><td>1</td><td>replace</td><td>$rpl</td></tr>");
msg("<tr><td>2</td><td>delete</td><td>$del</td></tr>");
msg("<tr><td>3</td><td>encrypt</td><td>$enc</td></tr>");
msg("<tr><td>4</td><td>decrypt</td><td>$dec</td></tr>");
msg("<tr><td>5</td><td>reverse</td><td>$rev</td></tr>");
msg("<tr><td>6</td><td>double</td><td>$doub</td></tr>");

msg("</table></center>");
}
else if($_POST['choice']=="Waiting Jobs"){

getconn();

if(!mysql_select_db("wordserver"))msg("error, database selection failed!....");
$rset="select pending.typeOftask,pending.body,pending.timepost from pending where pending.ordering=0";
if(!$qt=mysql_query($rset,getconn())) msg("database query failed!");
else{
	msg("<h1><u><center>Waiting Jobs at this Instance ...................</center></u></h1>");
	msg("<center><table border=\"1\"><tr><th>Sno</th><th>Command Name</th><th>String Body</th><th>Time Of Posting</th></tr>");
	for($rw=0;$rw<mysql_num_rows($qt);$rw++){
		$rq=mysql_fetch_row($qt);
                $rw1=$rw+1; 
		msg("<tr>");
msg("<td>".$rw1."</td>");

$rt = $rq[0]==0?"replace":($rq[0]==1?"delete":($rq[0]==2?"encrypt":($rq[0]==3?"decrypt":($rq[0]==4?"reverse":"double"))));
msg("<td>".$rt."</td>");
msg("<td>".$rq[1]."</td>");
msg("<td>".$rq[2]."</td>");
msg("</tr>");
		}
	msg("</table></center>");
	
}

}
/*else if($_POST['choice']=="Average Waiting Time"){

$conn = getconn();
$rs="select typeoftask from pending where status = 0";
if(!mysql_select_db("wordserver"))msg(msql_error());
if(!$returnq=mysql_query($rs,$conn)){msg(mysql_error()); }

msg("");
msg("<table border=\"1\"><caption>Failed Jobs at this instance........</caption>");
msg("<tr><th>command argument</th><th>string name</th><th>time of post</th></tr>");

for($rw=0;$r<mysql_num_rows($returnq);$rw++){
	$rows=mysql_fetch_row($returnq);
	msg("<tr><th>".$rows[1]."</th><th>".$rows[2]."</th><th>".$rows[3]."</th></tr>");
	
}
msg("</table>");

}
*/else{
msg("<p style=\"font-size:50px\">Currently Executing Jobs</p>");
msg("<table name=\"home\" border=\"1\" align=\"center\"><tr><th>Sno</th><th>Command Name</th><th>Command Argument</th></tr>");
	
$q="select typeOftask,body from pending where status=1";
$conn= getconn();
if(mysql_select_db("wordserver")!=0)echo("error in getting the connection");

if(!$rset=mysql_query($q,$conn))die("error in getting connecion!....");
else{

for($i=0;$i<mysql_num_rows($rset);$i++){
$rows=mysql_fetch_row($rset);
echo("<tr>");
$ii = $i+1;
msg("<td>".$ii."</td>");
$g = $rows[0]==0?"replace":($rows[0]==1?"delete":($rows[0]==2?"encrypt":($rows[0]==3?"decrypt":($rows[0]==4?"reverse":"double"))));
msg("<td>".$g."</td>");
msg("<td>".$rows[1]."</td>");
msg("</tr>");

}
}


msg("</table>");

}
}



function index(){

form1();
msg("<p style=\"font-size:50px\">Currently Executing Jobs</p>");
msg("<table name=\"home\" border=\"1\" align=\"center\"><tr><th>Sno</th><th>Command Name</th><th>Command Argument</th></tr>");
	
$q="select typeOftask,body from pending where status=1";
$conn= getconn();
if(mysql_select_db("wordserver")!=0)msg(mysql_error());

if(!$rset=mysql_query($q,$conn))msg(mysql_error());
else{

for($i=0;$i<mysql_num_rows($rset);$i++){
$rows=mysql_fetch_row($rset);
echo("<tr>");
$ii = $i+1;
msg("<td>".$ii."</td>");
$g = $rows[0]==0?"replace":($rows[0]==1?"delete":($rows[0]==2?"encrypt":($rows[0]==3?"decrypt":($rows[0]==4?"reverse":"double"))));
msg("<td>".$g."</td>");
msg("<td>".$rows[1]."</td>");
msg("</tr>");

}
}


msg("</table>");


bottom();

}


function form1(){

msg("
<DOCTYPE html>
<html>
<head><title>JSS admin interface</title>
<style>
header{
	background-color:steelblue;
	color:white;
	text-align:center;
	padding:10px;
	font-size:30px
	}
nav{
	line-height:30px;
	background-color:#48D1CC;
	color:white;
	height:500px;
	width:250px;
	float:left;
	padding:15px;
	font-size:20px;
}
section{
	width:1020px;
	text-align:center;
	padding:10px;
	font-size:20px;
	background-color:light;
        

}
footer{
	background-color:steelblue;
	color:white;
	clear:both;
	text-align:center;
	padding:10px;
}


</style>

</head>
<body style=\"background-color: light-green;\">

    <header>	WELCOME TO JSS.	</header>
<nav>
<form name=\"jobs\" action=\"jobs.php\" method=\"POST\">
<ul type = \"none\">

	<li><input type=\"submit\" name=\"choice\" value=\"HOME\" style=\"background-color:steelblue;color:white;border-radius:20px;size:20px\" /></li>
	<li><input type=\"submit\" name=\"choice\" value=\"Average Processing Time\" style=\"background-color:steelblue;color:white;border-radius:20px;size:20px\"/></li>
	<li><input type=\"submit\" name=\"choice\" value=\"Waiting Jobs\"  style=\"background-color:steelblue;color:white;border-radius:20px;size:20px\"/></li>
	<li><input type=\"submit\" name=\"choice\" value=\"Successful Jobs\" style=\"background-color:steelblue;color:white;border-radius:20px;size:20px\" /></li>
	<!--<li><input type=\"submit\" name=\"choice\" value=\"Average Waiting Time\" style=\"background-color:steelblue;color:white;border-radius:20px;size:20px\" /></li>-->
</ul>
</form>
</nav>

<section>
");

}

function bottom(){
msg("
<!--<form action =\"Addusers.php\" method = \"post\">
	<p>Enter your username and password.</p>
	User name:<input type = \"text\" name = \"user name\"/><br/><br/>
	Password:<input type = \"text\" name = \"password\"><br/><br/>
	<input type = \"reset\" value = \"clear\"/>
	<input type = \"submit\" value = \"send\"/>--->
</section>

	<footer>
	User guide.
	</footer>

</body>
</html>
");




}
?>

