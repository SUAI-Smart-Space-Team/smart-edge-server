using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace sitesuai.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";
            return View();
        }

        [HttpPost]
        public RedirectResult SetValue(string coolerSpeed, string coolerColor)
        {
            //TODO: write to db
            System.Diagnostics.Debug.WriteLine(coolerSpeed);
            return Redirect("Index");
        }

        [HttpPost]
        public RedirectResult SetPValue(string pumpSpeed, string pumpColor)
        {
            //TODO: write to db
            System.Diagnostics.Debug.WriteLine(pumpSpeed);
            return Redirect("Index");
        }
    }
}