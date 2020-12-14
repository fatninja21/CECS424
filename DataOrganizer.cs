using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Xml.Linq;

namespace DataOrganizer
{
    internal class MainClass
    {
        //used to enumerate through all directories in order to find information of each file in each directory
        private static IEnumerable<string> EnumerateFilesRecursively(string path)
        {

            var allFiles = Directory.GetFiles(path, ".", SearchOption.AllDirectories);// gets all directories in selected area
   
                foreach (string files in allFiles)//itterate through directory for files
                {
                    yield return files;//return one file at a time
                }
        }

        //format to readable sizes
        private static string FormatByteSize(long byteSize)
        {
            string[] units = { "bytes", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB" };//hold every type of size we can have of bytes
            var incrementUnit = 0; //increment unit starts at bytes
            double byteSizeD = byteSize;//temp value to hold current byteSize
            while (Math.Round(byteSizeD / 1024) >= 1) //while loop to change unit type until it is met
            {
                byteSizeD /= 1024;// divides temp bytesize by 24 for next loop
                incrementUnit++;//increment unit counter
            }
            return string.Format("{0:0.##}{1}", byteSizeD, units[incrementUnit]); //return formated output
        
    }

        //Create a HTML report file
        private static XDocument CreateReport(IEnumerable<string> files)
            => new XDocument( //create a new document
                new XDocumentType("html", null, null, null), //type of document is html
                    new XElement("html", //create html element in doc
                        new XElement("head", //create head for the document
                            new XElement("title", "Extension Information Report"), //title for the table
                            new XElement("style", "table, th, td { border: 2px solid black; }") //select style for the table
                        ),
                        new XElement("body",  //creating new elemtn for body of table
                            new XElement("table", //creating new elemtn for the table
                                new XElement("thead", //create new element for threat
                                    new XElement("tr",//row inforamtion
                                        new XElement("th", "Type"), //header cell defined as Type
                                        new XElement("th", "Count"), //header cell defined as Count
                                        new XElement("th", "Size") //header cell defined as Size
                                    )
                                ),
                                new XElement("tbody", //group body content
                                    from file in files //group files from files being passed
                                    group file by Path.GetExtension(file).ToLower() into fileGroup //lowercase all data being retrieved
                                    let totalSize = fileGroup.Sum(file => new FileInfo(file).Length)
                                    orderby totalSize descending //ordering all the information by total size in decending order
                                    select new XElement("tr", //row inforamtion
                                        new XElement("td", fileGroup.Key), //File extension that is displayed
                                        new XElement("td", fileGroup.Count()), //count that is displayed
                                        new XElement("td", FormatByteSize(totalSize)) //total memory in readable bytes that is displayed
                                )
                            )
                        )
                    )
                )
            );


        
        public static void Main(string[] args)
        {

            string folder = args[0]; //input folder path
            string reportFile = args[1]; //output file path
            //string folder = "C:\\Users\\willy\\Downloads"; //hardcoded folder location for input folder
            //string reportFile = "C:\\Users\\willy\\source\\repos\\cecs-424-spring-2020-assignment-4\\cecs424-assignment_4\\cecs424-assignment_4\\data2.html";//hardcoded output file
            CreateReport(EnumerateFilesRecursively(folder)).Save(reportFile);//generate report and save it to destination
        }

    } 
                                
}