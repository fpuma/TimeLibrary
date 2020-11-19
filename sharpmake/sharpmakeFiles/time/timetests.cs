using Sharpmake;

namespace Puma
{
    [Sharpmake.Generate]
    class TimeTests : Puma.Common.IMyApplication
    {
        public TimeTests()
            : base("TimeTests", @"timetests")
        { }

        public override void ConfigureAll(Configuration conf, Sharpmake.Target target)
        {
            base.ConfigureAll(conf, target);

            conf.AddPublicDependency<Puma.Time>(target);

            conf.Options.Add(Sharpmake.Options.Vc.General.TreatWarningsAsErrors.Enable);
        }
    }
}