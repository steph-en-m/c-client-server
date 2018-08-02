
<?php 

function getconn(){

return mysql_connect("localhost:3306","root","");
}
function msg($p){
	echo($p);	
	
}
function display(){
if($POST[choice]=="HOME"){
msg("<p style=\"font-size:50px\">Currently Executing Jobs</p>");
msg("<table name=\"home\" border=\"1\" align=\"center\"><tr><th>Sno</th><th>Command Name</th><th>Command Argument</th></tr>");
	
$q="select typeOftask,body from pending where status=1";
$conn= getconn();
if(mysql_select_db("wordserver")!=0)echo("error in getting the connection");

if(!$rset=mysql_query($q,$conn))die("error in getting connecion!....");
else{
	for($i=0;$i<mysql_num_rows[$rset];$i++){
$rows=mysql_fetch_row($rset);
echo("<tr>");
$ii = $i+1;
msg("<td>".$ii."</td>");
$g = $rows[0]==0?"replace":($rows[0]==1?"delete":($rows[0]==2?"encrypt":($rows[0]==3?"decrypt":($rows[0]==4?"reverse":"double"))));
msg("<td>".$g."</td>");
msg"<td>".$rows[1]."</td>");
msg("</tr>");

}
}
}
msg("</table>");
else if($POST[choice]=="Average Processing Time"){
msg("<p style=\"font-size:50px\">Average Time at this instabce</p>");
$qt="select taskid,timecomplete,timepost from ready,pending where ready.taskid=pending.idno ";
$conn=getconn;
if(mysql_select_db("wordserver")!=0)msg("error in database selection");
if(!mysql_query($qt,$conn))msg(mysql_error());

else{
$totaljobs=mysql_num_rows($rs);$tfin=0;
for($i=0;$i<mysql_num_rows[$rs];$i++){
$qrw=mysql_fetch_row[$rs];
$tfin = $tfin + ($qrw[1]-$qrw[2]);
}
}
$avgtime=($tfin/$totaljobs);
msg("Number of success jobs: ".$totaljobs "\t");
msg("Total time spent to process Jobs: ".$tfin);
msg("Average time spent for processing: ".$avgtime);
}

else if($POST[choice]=="Successful Jobs"){
$conn = getconn();
if(!mysql_select_db("wordserver"))msg("database selection failed!...........");
$rset="select typeOftask from pending where status=2";
$query=mysql_query($rset,$conn);
$rpl=0;$del=0;$enc=0;$dec=0;$doub=0;$rev=0;$reply=0;
msg("<table border=\"1\">");
for($i=0;$i<mysql_num_rows[$query];$++){
$rw=mysql_fetch_row[$query];
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


}
else if($POST[choice]=="Waiting Jobs"){

getconn();
if(!mysql_select_db("wordserver"))msg("error, database selection failed!....");
$rset="select typeOftask from pending where status <> 2";
$qt=msql_query($rset,getconn());
if($qt!=0)  msg("database query failed!");
else{
	msg("<h1><u><center>Waiting Jobs at this Instance ...................</center></u></h1>");
	msg("<table border=\"1\"><tr><th>Command Name</th><th>Time Of Posting</th></tr>");
	for($rw=0;$rw<mysql_num_rows[$qt];$rw++){
		$rq=mysql_affected_rows($qt);
		msg("<tr><td>".$rq[1]."</td><td>".$rq[3]."</td></tr>");
		}
	msg("</table>");
	
}

}
else if($POST[choice]=="Failed Jobs"){
$conn = getconn();
$rs="select typeoftask from pending where status = 0";
$returnq=msql_query($rs,$conn);
if($returnq!=0){msg(No database selsected!....); }
msg("<h1><u><center>Failed Jobs at this instance........");
msg("<table border=\"1\"><tr><th>command argument</th><th>string name</th><th>time of post</th></tr>");
for($rw=0;$rw<mysql_num_rows[$returnq];$rw++){
	$rows=mysql_affected_rows($returnq);
	msg("<tr><th>".$rows[1]."</th><th".$rows[2]."</th><th>".$rows[3]."</th></tr>");
	
}


}
}
?>

